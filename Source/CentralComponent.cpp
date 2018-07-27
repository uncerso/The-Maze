#include "CentralComponent.h"
#include "Control.h"
#include "PixelShape.h"

CentralComponent::CentralComponent()
	: Component("Central Component")
	, gld(&openGLContext)
	, sp("Menu", 500, false)
{
	button1.setButtonText("menu");
	button1.setCallback([this](Button *) {sp.showOrHide(!sp.isPanelShowing()); });
	addAndMakeVisible(button1);

	shouldDraw.setButtonText("Draw");
	shouldDraw.setCallback([this](Button *) {
		mazeGenerator.generate(rand(), getWidth(), getHeight(), MazeGenerator::MazeType::binaryTree);

		auto points = mazeGenerator.getMazeAsPointsToDraw(MazeGenerator::DrawType::wave);
//		int pointsSize = points.amountOfIntervals();
		Shape * sh = new PixelShape(
			std::move(points),
			[gc = GreatColor()](int) mutable{
			return gc.getNextColor();
		}
		);
		//[maxIndex = pointsSize](int i) {
		//	auto newColor = static_cast<unsigned char>(255.0 * (1 - static_cast<double>(i) / maxIndex));
		//	return Color(newColor, newColor, newColor);
		gld.loadData(std::unique_ptr<Shape>(sh));
	});
	addAndMakeVisible(shouldDraw);

	sp.setContent(new Menu);
	addAndMakeVisible(sp);

	openGLContext.attachTo(*this);
}

CentralComponent::~CentralComponent() {
	openGLContext.detach();
	openGLContext.setRenderer(nullptr);
}

void CentralComponent::paint(Graphics&) {}

void CentralComponent::resized() {
	gld.setBounds(0, 0, getWidth(), getHeight());
	button1.setBounds(0, 0, static_cast<int>(getWidth() * 0.05), static_cast<int>(getHeight() * 0.05));
	shouldDraw.setBounds(static_cast<int>(getWidth() * 0.05), 0, static_cast<int>(getWidth() * 0.10), static_cast<int>(getHeight() * 0.05));
}
