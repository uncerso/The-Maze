#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class CentralComponent;

class MainForm
    : public DocumentWindow 
{
public:
	MainForm();
	~MainForm();

	void closeButtonPressed();
private:
	std::unique_ptr<CentralComponent> centralComponent;
	std::unique_ptr<LookAndFeel> laf;
};