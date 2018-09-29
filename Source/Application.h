#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainForm;

class Application
    : public JUCEApplication
{
public:
	Application();
	~Application();

	void initialise(String const & commandLineParameters);
	void shutdown();
	void systemRequestedQuit();
	const String getApplicationName();
	const String getApplicationVersion();
	bool moreThanOneInstanceAllowed();
private:
	std::unique_ptr<MainForm> mainWindow;
};