#include "CentralComponent.h"
#include "Control.h"
#include "ButtonManager.h"

CentralComponent::CentralComponent()
	: Component("Central Component")
	, sp("Menu", 500, false)
{
	gld.afterRender([this](Graphics & g) {
		lb.setText(String(rand()), NotificationType::dontSendNotification);
		if (sp.isPanelShowing())
			sp.paint(g);
	});
	addAndMakeVisible(gld);

	button1.setButtonText("menu");
	ButtonManager::addLink(&button1, [this] {sp.showOrHide(!sp.isPanelShowing()); });
	addAndMakeVisible(button1);

	sp.setContent(new Menu);
	addAndMakeVisible(sp);

	lb.setText("initText", NotificationType::dontSendNotification);
	addAndMakeVisible(lb);
}

CentralComponent::~CentralComponent() {
	ButtonManager::removeLink(&button1);
}

void CentralComponent::paint(Graphics& canvas) {
	canvas.fillAll(Colour::fromRGB(210, 210, 210));
}

void CentralComponent::resized() {
	gld.setBounds(0, static_cast<int>(getHeight() * 0.05), getWidth(), static_cast<int>(getHeight() * 0.95));
	button1.setBounds(0, 0, static_cast<int>(getWidth() * 0.05), static_cast<int>(getHeight() * 0.05));
	lb.setBounds(static_cast<int>(getWidth() * 0.05), 0, static_cast<int>(getWidth() * 0.10), static_cast<int>(getHeight() * 0.05));
	//grabKeyboardFocus();
}
