#include "MainForm.h"
#include "CentralComponent.h"
#include "OpenGLDrawer.h"

MainForm::MainForm() 
    : DocumentWindow(
	    JUCEApplication::getInstance()->getApplicationName(),
	    LookAndFeel_V4::getMidnightColourScheme().getUIColour(LookAndFeel_V4::ColourScheme::UIColour::windowBackground),
	    allButtons)
	, laf(new LookAndFeel_V4(LookAndFeel_V4::getMidnightColourScheme()))
{
	setLookAndFeel(laf.get());
	laf->setColour(Slider::ColourIds::backgroundColourId, findColour(Slider::ColourIds::trackColourId).withAlpha(0.2f));
	centreWithSize(static_cast<int>(getParentWidth()*0.9), static_cast<int>(getParentHeight()*0.9));
	setResizable(true, false);
	setVisible(true);
	centralComponent.reset(new CentralComponent());
	setContentOwned(centralComponent.get(), false);
}

MainForm::~MainForm() {
	setLookAndFeel(nullptr);
}

void MainForm::closeButtonPressed() {
	JUCEApplication::getInstance()->systemRequestedQuit();
}
