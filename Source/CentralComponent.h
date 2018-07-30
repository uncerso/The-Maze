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
	
	std::unique_ptr<Menu> configureMenu();

private:
#if JUCE_OPENGL
	OpenGLContext openGLContext;
#endif
	OpenGLDrawer openGLDrawer;
	SidePanel menuSidePanel;
	TextButton button1;

	TextButton shouldDraw;

	MazeGenerator mazeGenerator;

	//Configs
	MazeGenerator::MazeType mazeType;
	MazeGenerator::DrawType drawType;
	bool instantDrawing;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CentralComponent)
};