#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Menu.h"
#include "OpenGLDrawer.h"
#include "MazeGenerator.h"

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
	OpenGLDrawer openGLDrawer;
	SidePanel sp;
	TextButton button1;

	TextButton shouldDraw;

	MazeGenerator mazeGenerator;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CentralComponent)
};