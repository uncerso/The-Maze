#include "MainForm.h"
#include "CentralComponent.h"
#include "OpenGLDrawer.h"

MainForm::MainForm() 
    : DocumentWindow(
	    JUCEApplication::getInstance()->getApplicationName(),
	    Colour::fromRGB(97, 90, 117),
	    allButtons)
{
	setColour(DocumentWindow::textColourId, Colour::fromRGB(177, 170, 197));
	centreWithSize(static_cast<int>(getParentWidth()*0.9), static_cast<int>(getParentHeight()*0.9));
	setResizable(true, false);
	setVisible(true);
	centralComponent.reset(new CentralComponent());
	setContentOwned(centralComponent.get(), false);
}

void MainForm::closeButtonPressed() {
	JUCEApplication::getInstance()->systemRequestedQuit();
}
