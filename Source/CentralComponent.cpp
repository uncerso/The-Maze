#include "CentralComponent.h"
#include "Control.h"

CentralComponent::CentralComponent()
	: Component("Central Component")
	, gld(&openGLContext)
	, sp("Menu", 500, false)
{
	button1.setButtonText("menu");
	button1.setCallback([this](Button *) {sp.showOrHide(!sp.isPanelShowing()); lb.setText(String(rand()),dontSendNotification); });
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
	button1.setBounds(0, 0, static_cast<int>(getWidth() * 0.05), static_cast<int>(getHeight() * 0.05));
	lb.setBounds(static_cast<int>(getWidth() * 0.05), 0, static_cast<int>(getWidth() * 0.10), static_cast<int>(getHeight() * 0.05));
}
