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

void CentralComponent::paint(Graphics&) {
	//canvas.fillAll(Colour::fromRGB(210, 210, 210));
}

void CentralComponent::resized() {
	//	gld.setBounds(0, static_cast<int>(getHeight() * 0.05), getWidth(), static_cast<int>(getHeight() * 0.95));
	button1.setBounds(0, 0, static_cast<int>(getWidth() * 0.05), static_cast<int>(getHeight() * 0.05));
	lb.setBounds(static_cast<int>(getWidth() * 0.05), 0, static_cast<int>(getWidth() * 0.10), static_cast<int>(getHeight() * 0.05));
	//grabKeyboardFocus();
}
