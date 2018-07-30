#include "CentralComponent.h"
#include "Control.h"
#include "PixelShape.h"

CentralComponent::CentralComponent()
	: Component("Central Component")
	, openGLDrawer(&openGLContext)
	, menuSidePanel("Menu", 500, false)
	, instantDrawing(false)
{
	button1.setButtonText("menu");
	button1.onClick = [this] {menuSidePanel.showOrHide(!menuSidePanel.isPanelShowing()); };
	addAndMakeVisible(button1);

	shouldDraw.setButtonText("Draw");
	shouldDraw.onClick = [this] {
		mazeGenerator.generate(rand(), getWidth(), getHeight(), mazeType);

		auto points = mazeGenerator.getMazeAsPointsToDraw(drawType);
		//		int pointsSize = points.amountOfIntervals();
		Shape * sh = new PixelShape(
			std::move(points),
			[gc = GreatColor()](int) mutable{ return gc.getNextColor(); },
			instantDrawing
		);
		//[maxIndex = pointsSize](int i) {
		//	auto newColor = static_cast<unsigned char>(255.0 * (1 - static_cast<double>(i) / maxIndex));
		//	return Color(newColor, newColor, newColor);
		openGLDrawer.loadData(std::unique_ptr<Shape>(sh));
	};
	addAndMakeVisible(shouldDraw);

	menuSidePanel.setContent(configureMenu().release(), true);
	addAndMakeVisible(menuSidePanel);

	openGLContext.attachTo(*this);
}

CentralComponent::~CentralComponent() {
	openGLContext.detach();
	openGLContext.setRenderer(nullptr);
}

void CentralComponent::paint(Graphics&) {}

void CentralComponent::resized() {
	openGLDrawer.setBounds(0, 0, getWidth(), getHeight());
	button1.setBounds(0, 0, static_cast<int>(getWidth() * 0.05), static_cast<int>(getHeight() * 0.05));
	shouldDraw.setBounds(static_cast<int>(getWidth() * 0.05), 0, static_cast<int>(getWidth() * 0.10), static_cast<int>(getHeight() * 0.05));
}

std::unique_ptr<Menu> CentralComponent::configureMenu() {
	using std::move;
	using std::make_unique;

	auto menu = make_unique<Menu>();

	int radioGroupID = 1;

	//=========================================================================
	{
		++radioGroupID;

		auto lbAlg = make_unique<Label>();
		lbAlg->setText("Choose algorithm:", NotificationType::dontSendNotification);

		auto b1Alg = make_unique<TextButton>();
		b1Alg->setButtonText("Binary tree");
		b1Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnBottom);
		b1Alg->setRadioGroupId(radioGroupID);
		b1Alg->setClickingTogglesState(true);
		b1Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::binaryTree; };
		b1Alg->setToggleState(true, NotificationType::dontSendNotification);
		mazeType = MazeGenerator::MazeType::binaryTree;

		auto b2Alg = make_unique<TextButton>();
		b2Alg->setButtonText("Sidewinder");
		b2Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnTop | TextButton::ConnectedEdgeFlags::ConnectedOnBottom);
		b2Alg->setRadioGroupId(radioGroupID);
		b2Alg->setClickingTogglesState(true);
		b2Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::sidewinder; };

		auto b3Alg = make_unique<TextButton>();
		b3Alg->setButtonText("noname");
		b3Alg->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnTop);
		b3Alg->setRadioGroupId(radioGroupID);
		b3Alg->setClickingTogglesState(true);
		b3Alg->onClick = [this] {mazeType = MazeGenerator::MazeType::noname; };

		menu->addGroup(move(lbAlg), move(b1Alg), move(b2Alg), move(b3Alg));
	}
	//=========================================================================
	{
		++radioGroupID;

		auto lbDrawType = make_unique<Label>();
		lbDrawType->setText("Choose draw type:", NotificationType::dontSendNotification);

		auto b1DrawType = make_unique<TextButton>();
		b1DrawType->setButtonText("One frame");
		b1DrawType->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnBottom);
		b1DrawType->setRadioGroupId(radioGroupID);
		b1DrawType->setClickingTogglesState(true);
		b1DrawType->onClick = [this] {drawType = MazeGenerator::DrawType::oneFrame; };

		auto b2DrawType = make_unique<TextButton>();
		b2DrawType->setButtonText("Wave");
		b2DrawType->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnTop | TextButton::ConnectedEdgeFlags::ConnectedOnBottom);
		b2DrawType->setRadioGroupId(radioGroupID);
		b2DrawType->setClickingTogglesState(true);
		b2DrawType->onClick = [this] {drawType = MazeGenerator::DrawType::wave; };
		b2DrawType->setToggleState(true, NotificationType::dontSendNotification);
		drawType = MazeGenerator::DrawType::wave;

		auto b3DrawType = make_unique<TextButton>();
		b3DrawType->setButtonText("Wave with repainting walls");
		b3DrawType->setConnectedEdges(TextButton::ConnectedEdgeFlags::ConnectedOnTop);
		b3DrawType->setRadioGroupId(radioGroupID);
		b3DrawType->setClickingTogglesState(true);
		b3DrawType->onClick = [this] {drawType = MazeGenerator::DrawType::withWalls; };

		menu->addGroup(move(lbDrawType), move(b1DrawType), move(b2DrawType), move(b3DrawType));
	}
	//=========================================================================
	{
		auto b = make_unique<TextButton>();
		b->setButtonText("Instant drawing");
		b->setClickingTogglesState(true);
		b->onClick = [this, self = b.get()] {instantDrawing = self->getToggleState(); };
		b->setToggleState(instantDrawing, NotificationType::dontSendNotification);

		menu->addGroup(move(b));
	}

	return menu;
}