#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "menu.h"
#include "OpenGLDrawer.h"
#include "CustomButton.h"

class CentralComponent
	: public Component
{
public:
	CentralComponent();
	~CentralComponent();

	void paint(Graphics&);
	void resized();
	
private:
#if JUCE_OPENGL
	OpenGLContext openGLContext;
#endif
	OpenGLDrawer gld;
	SidePanel sp;
	CustomButton<TextButton> button1;

	Label lb;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CentralComponent)
};