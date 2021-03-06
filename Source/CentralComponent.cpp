#include <cmath>
#include "CentralComponent.h"
#include "PixelShape.h"
#include "DensePixelShape.h"

CentralComponent::CentralComponent()
	: Component("Central Component")
	, openGLDrawer(&openGLContext)
	, menuSidePanel("Menu", 500, false)
	, shaderMode(OpenGLDrawer::ShaderMode::dense)
	, instantDrawing(false)
	, pointSize(1)
	, delayBetweenFramesGeneration(5)
	, shouldTreadEnd(false)
	, flag(false)
{
	constexpr auto button_alpha = 0.7;
	menuSidePanel.setShadowWidth(0);

	menuButton.setButtonText("menu");
	menuButton.setAlpha(button_alpha);
	menuButton.onClick = [this] {menuSidePanel.showOrHide(!menuSidePanel.isPanelShowing()); };
	addAndMakeVisible(menuButton);

	auto const runDrawing = [this] {
		while (true) {
			std::unique_lock<std::mutex> lk(mt);
			cv.wait(lk, [this] {return flag.load(); });
			flag = false;
			if (shouldTreadEnd) return;
			auto const renderingScale = openGLContext.getRenderingScale();
			auto width = static_cast<int>(std::ceil(getWidth() * renderingScale));
			auto height = static_cast<int>(std::ceil(getHeight() * renderingScale));
			auto const pntSize = pointSize.load();
			mazeGenerator.generate(seed, width / pntSize, height / pntSize, mazeType);
			std::unique_ptr<Shape> shape;
			if (shaderMode == OpenGLDrawer::ShaderMode::sparse)
				shape.reset(new PixelShape(mazeGenerator.getMazeAsPointsToDraw(drawType, 2), paintingMethod, instantDrawing));
			else
				shape.reset(new DensePixelShape(mazeGenerator.getMazeAsPointsToDraw(drawType, 5), paintingMethod, instantDrawing));
			openGLDrawer.setBounds(0, 0, static_cast<float>(width) / pntSize, static_cast<float>(height) / pntSize);
			openGLDrawer.setPointSize(pntSize);
			openGLDrawer.changeFrequency(delayBetweenFramesGeneration);
			const MessageManagerLock mmLock;
			openGLDrawer.loadData(move(shape), shaderMode);
			shouldDraw.setEnabled(true);
		}
	};
	thrd = std::thread(runDrawing);

	shouldDraw.setButtonText("Draw");
	shouldDraw.setAlpha(button_alpha);
	shouldDraw.onClick = [this] { shouldDraw.setEnabled(false); menuSidePanel.showOrHide(false); wakeUpTread(); };
	addAndMakeVisible(shouldDraw);

	auto configReturn = configureMenu();
	shouldCallWhenResized = std::move(configReturn.snd);
	menuSidePanel.setContent(configReturn.fst.release(), true);
	addAndMakeVisible(menuSidePanel);

	openGLContext.attachTo(*this);
}

CentralComponent::~CentralComponent() {
	shouldTreadEnd = true;
	wakeUpTread();
	thrd.join();
	openGLContext.detach();
	openGLContext.setRenderer(nullptr);
}

void CentralComponent::wakeUpTread() {
	{
		std::lock_guard<std::mutex> g(mt);
		flag = true;
	}
	cv.notify_one();
}

void CentralComponent::paint(Graphics&) {}

void CentralComponent::resized() {
	auto const renderingScale = static_cast<float>(openGLContext.getRenderingScale());
	auto const width = getWidth();
	auto const height = getHeight();
	openGLDrawer.setBounds(0, 0, std::ceil(width * renderingScale) / pointSize, std::ceil(height * renderingScale) / pointSize);
	shouldCallWhenResized();
	menuButton.setBounds(0, 0, static_cast<int>(width * 0.05), static_cast<int>(height * 0.05));
	shouldDraw.setBounds(static_cast<int>(width * 0.05), 0, static_cast<int>(width * 0.10), static_cast<int>(height * 0.05));
}

Pair<std::unique_ptr<Menu>, std::function<void()> > CentralComponent::configureMenu() {
	using std::move;
	using std::make_unique;

	auto menu = make_unique<Menu>();
	std::vector<std::function<void()> > functionsForReturn;

	int radioGroupID = 1;

	//=========================================================================
	{
		++radioGroupID;

		auto lbAlg = make_unique<Label>();
		lbAlg->setText("Algorithm:", NotificationType::dontSendNotification);

		auto b1Alg = make_unique<TextButton>();
		b1Alg->setButtonText("Binary tree");
		b1Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b1Alg->setRadioGroupId(radioGroupID);
		b1Alg->setClickingTogglesState(true);
		b1Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::binaryTree; };

		auto b2Alg = make_unique<TextButton>();
		b2Alg->setButtonText("Sidewinder");
		b2Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft);
		b2Alg->setRadioGroupId(radioGroupID);
		b2Alg->setClickingTogglesState(true);
		b2Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::sidewinder; };

		auto b3Alg = make_unique<TextButton>();
		b3Alg->setButtonText("Prim's");
		b3Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b3Alg->setRadioGroupId(radioGroupID);
		b3Alg->setClickingTogglesState(true);
		b3Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::prime; };

		auto b4Alg = make_unique<TextButton>();
		b4Alg->setButtonText("Kruskal's");
		b4Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft | TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b4Alg->setRadioGroupId(radioGroupID);
		b4Alg->setClickingTogglesState(true);
		b4Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::kruskal; };

		auto b5Alg = make_unique<TextButton>();
		b5Alg->setButtonText("Recursive backtracker");
		b5Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b5Alg->setRadioGroupId(radioGroupID);
		b5Alg->setClickingTogglesState(true);
		b5Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::recursiveBacktracker; };

		auto b6Alg = make_unique<TextButton>();
		b6Alg->setButtonText("Recursive division");
		b6Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft | TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b6Alg->setRadioGroupId(radioGroupID);
		b6Alg->setClickingTogglesState(true);
		b6Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::recursiveDivision; };

		auto b7Alg = make_unique<TextButton>();
		b7Alg->setButtonText("Hunt-and-Kill");
		b7Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft);
		b7Alg->setRadioGroupId(radioGroupID);
		b7Alg->setClickingTogglesState(true);
		b7Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::huntAndKill; };

		auto b8Alg = make_unique<TextButton>();
		b8Alg->setButtonText("Eller's");
		b8Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft);
		b8Alg->setRadioGroupId(radioGroupID);
		b8Alg->setClickingTogglesState(true);
		b8Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::eller; };

		b4Alg->setToggleState(true, NotificationType::sendNotificationSync);

		menu->addGroup(move(lbAlg), move(b1Alg), move(b2Alg));
		menu->addGroup(move(b3Alg), move(b4Alg), move(b8Alg));
		menu->addGroup(move(b5Alg), move(b6Alg), move(b7Alg));
		menu->addSeparatorLines();
	}
	//=========================================================================
	{
		++radioGroupID;

		auto lbDrawType = make_unique<Label>();
		lbDrawType->setText("Draw type:", NotificationType::dontSendNotification);

		auto b1DrawType = make_unique<TextButton>();
		b1DrawType->setButtonText("One frame");
		b1DrawType->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b1DrawType->setRadioGroupId(radioGroupID);
		b1DrawType->setClickingTogglesState(true);
		b1DrawType->onClick = [this] {drawType = MazeGenerator::DrawType::oneFrame; };

		auto b2DrawType = make_unique<TextButton>();
		b2DrawType->setButtonText("Wave");
		b2DrawType->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft | TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b2DrawType->setRadioGroupId(radioGroupID);
		b2DrawType->setClickingTogglesState(true);
		b2DrawType->onClick = [this] {drawType = MazeGenerator::DrawType::wave; };

		auto b3DrawType = make_unique<TextButton>();
		b3DrawType->setButtonText("Wave with repainting walls");
		b3DrawType->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft);
		b3DrawType->setRadioGroupId(radioGroupID);
		b3DrawType->setClickingTogglesState(true);
		b3DrawType->onClick = [this] {drawType = MazeGenerator::DrawType::withWalls; };

		b3DrawType->setToggleState(true, NotificationType::sendNotificationSync);

		menu->addGroup(move(lbDrawType), move(b1DrawType), move(b2DrawType), move(b3DrawType));
		menu->addSeparatorLines();
	}
	//=========================================================================
	{
		++radioGroupID;

		auto lbColor = make_unique<Label>();
		lbColor->setText("Painting method:", NotificationType::dontSendNotification);

		auto b1Color = make_unique<TextButton>();
		b1Color->setButtonText("Gradient");
		b1Color->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnRight);
		b1Color->setRadioGroupId(radioGroupID);
		b1Color->setClickingTogglesState(true);
		b1Color->onClick = [this] {
			paintingMethod = [this](int i, int size) {
				auto newColor = static_cast<unsigned char>(255.0 * (1 - static_cast<double>(i) / size));
				return Color(newColor, newColor, newColor);
			};
		};

		auto b2Color = make_unique<TextButton>();
		b2Color->setButtonText("Rainbow");
		b2Color->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft);
		b2Color->setRadioGroupId(radioGroupID);
		b2Color->setClickingTogglesState(true);
		b2Color->onClick = [this] { paintingMethod = [this, gc = GreatColor()](int, int) mutable { return gc.getNextColor(pointSize - 1); }; };

		b2Color->setToggleState(true, NotificationType::sendNotificationSync);

		menu->addGroup(move(lbColor), move(b1Color), move(b2Color));
		menu->addSeparatorLines();
	}
	//=========================================================================
	{
		auto lbSeed = make_unique<Label>();
		lbSeed->setText("Seed:", NotificationType::dontSendNotification);

		auto teSeed = make_unique<TextEditor>();
		teSeed->setMultiLine(false);
		teSeed->onTextChange = [this, self = teSeed.get()]{ seed = static_cast<unsigned int>(self->getText().getIntValue()); };
		teSeed->setInputRestrictions(9, "1234567890");
		teSeed->setJustification(Justification::centred);

		auto bSeed = make_unique<TextButton>();
		bSeed->setButtonText("Generate randomly");
		bSeed->onClick = [this, seedEditor = teSeed.get()]{ seedEditor->setText(String(randomDevice() % 1'000'000'000)); };
		bSeed->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnLeft);

		bSeed->setToggleState(true, NotificationType::sendNotificationSync);

		menu->addGroup(move(lbSeed), move(teSeed), move(bSeed));
		menu->addSeparatorLines();
	}
	//=========================================================================
	{
		auto lbPaintSpeed = make_unique<Label>();
		lbPaintSpeed->setText("Point size:", NotificationType::dontSendNotification);

		auto sPaintSpeed = make_unique<Slider>();
		sPaintSpeed->setRange(1, 2, 1);
		sPaintSpeed->setTextValueSuffix(" pixels");
		sPaintSpeed->onValueChange = [this, self = sPaintSpeed.get()]{ pointSize = static_cast<unsigned int>(self->getValue()); };
		sPaintSpeed->setValue(pointSize);
		functionsForReturn.emplace_back([this, sPS = sPaintSpeed.get()]{ sPS->setRange(1, std::min(getWidth(), getHeight()) * openGLContext.getRenderingScale() / 7, 1); pointSize = static_cast<unsigned int>(sPS->getValue()); });

		menu->addGroup(move(lbPaintSpeed));
		menu->addGroup(move(sPaintSpeed));
		menu->addSeparatorLines();
	}
	//=========================================================================
	{
		auto lbDrawingSpeed = make_unique<Label>();
		lbDrawingSpeed->setText("The delay between frames generation:", NotificationType::dontSendNotification);

		auto sDrawingSpeed = make_unique<Slider>();
		sDrawingSpeed->setRange(1, 1000, 1);
		sDrawingSpeed->setTextValueSuffix(" ms");
		sDrawingSpeed->onValueChange = [this, self = sDrawingSpeed.get()]{ delayBetweenFramesGeneration = static_cast<unsigned int>(self->getValue()); };
		sDrawingSpeed->setValue(delayBetweenFramesGeneration);

		auto bDrawingSpeed = make_unique<TextButton>();
		bDrawingSpeed->setButtonText("Instant drawing");
		bDrawingSpeed->setClickingTogglesState(true);
		bDrawingSpeed->onClick = [this, self = bDrawingSpeed.get()]{ instantDrawing = self->getToggleState(); };
		bDrawingSpeed->setToggleState(instantDrawing, NotificationType::dontSendNotification);

		menu->addGroup(move(lbDrawingSpeed));
		menu->addGroup(move(sDrawingSpeed));
		menu->addGroup(move(bDrawingSpeed));
		menu->addSeparatorLines();
	}
	//=========================================================================
	{
		auto lbResolution = make_unique<Label>();
		functionsForReturn.emplace_back([this, lb = lbResolution.get()]{
			auto const renderingScale = openGLContext.getRenderingScale();
			lb->setText("Field size: " + String(std::ceil(getWidth() * renderingScale)) + " x " + String(std::ceil(getHeight() * renderingScale)), dontSendNotification);
			});
		auto bShaderMode = make_unique<TextButton>();
		bShaderMode->setButtonText("GPU memory saving mode\n(not recommended)");
		bShaderMode->setClickingTogglesState(true);
		bShaderMode->onClick = [this, self = bShaderMode.get()]{ shaderMode = (self->getToggleState() ? OpenGLDrawer::ShaderMode::sparse : OpenGLDrawer::ShaderMode::dense); };

		menu->addGroup(move(lbResolution), move(bShaderMode));
	}
	return { move(menu),[funcs = move(functionsForReturn)] {for (auto & foo : funcs) foo(); } }; // menu && shouldCallWhenResized
}