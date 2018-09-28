#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Menu.h"
#include "OpenGLDrawer.h"
#include "MazeGenerator.h"
#include "Pair.h"
#include <random>
#include <mutex>
#include <thread>
#include <condition_variable>

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
	std::atomic<MazeGenerator::MazeType> mazeType;
	std::atomic<MazeGenerator::DrawType> drawType;
	std::atomic<bool> instantDrawing;
	std::function<Color(int, int)> paintingMethod;
	std::atomic<unsigned int> seed;
	std::atomic<unsigned int> pointSize;
	std::atomic<unsigned int> delayBetweenFramesGeneration;
	std::mutex mt;
	std::condition_variable cv;
	std::atomic<bool> shouldTreadEnd;
	std::atomic<bool> flag;
	std::thread thrd;

	void wakeUpTread();

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CentralComponent)
};
