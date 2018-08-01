#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Menu.h"
#include "OpenGLDrawer.h"
#include "MazeGenerator.h"
#include "Pair.h"
#include <random>

class CentralComponent
	: public Component
{
public:
	CentralComponent();
	~CentralComponent();

	void paint(Graphics&);
	void resized();
	
	Pair<std::unique_ptr<Menu>, std::function<void()> > configureMenu();

private:
#if JUCE_OPENGL
	OpenGLContext openGLContext;
#endif
	OpenGLDrawer openGLDrawer;
	SidePanel menuSidePanel;
	TextButton menuButton;

	TextButton shouldDraw;

	MazeGenerator mazeGenerator;
	
	std::random_device randomDevice;

	std::function<void()> shouldCallWhenResized;

	//Configs
	MazeGenerator::MazeType mazeType;
	MazeGenerator::DrawType drawType;
	bool instantDrawing;
	std::function<Color(int, int)> paintingMethod;
	unsigned int seed;
	unsigned int pointSize;
	unsigned int delayBetweenFramesGeneration;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CentralComponent)
};