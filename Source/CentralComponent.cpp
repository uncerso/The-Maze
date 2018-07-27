#include "CentralComponent.h"
#include "Control.h"
#include "PixelShape.h"

CentralComponent::CentralComponent()
	: Component("Central Component")
	, gld(&openGLContext)
	, sp("Menu", 500, false)
{
	button1.setButtonText("menu");
	button1.setCallback([this](Button *) {sp.showOrHide(!sp.isPanelShowing()); lb.setText(String(rand()), dontSendNotification); });
	addAndMakeVisible(button1);

	sp.setContent(new Menu);
	addAndMakeVisible(sp);

	lb.setText("initText", NotificationType::dontSendNotification);
	addAndMakeVisible(lb);

	openGLContext.attachTo(*this);
}

CentralComponent::~CentralComponent() {
	openGLContext.detach();
	openGLContext.setRenderer(nullptr);
}

void CentralComponent::paint(Graphics&) {}

void CentralComponent::resized() {
	gld.setBounds(50, 50, 200, 200);
	PixelShape * sh = new PixelShape(PointsToDraw(std::vector<float>({ 0, 0, 50, 100, 100, 0 }), std::vector<int>({ 0, 3 })), [](int ) {return Color(255 / 2, 255 / 2, 255 / 2); });
	gld.loadData(std::unique_ptr<Shape>(sh));
	button1.setBounds(0, 0, static_cast<int>(getWidth() * 0.05), static_cast<int>(getHeight() * 0.05));
	lb.setBounds(static_cast<int>(getWidth() * 0.05), 0, static_cast<int>(getWidth() * 0.10), static_cast<int>(getHeight() * 0.05));
}
