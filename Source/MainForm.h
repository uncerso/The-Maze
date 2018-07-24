#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class CentralComponent;

class MainForm
    : public DocumentWindow 
{
public:
	MainForm();
	~MainForm() = default;

	void closeButtonPressed();
private:
	std::unique_ptr<CentralComponent> centralComponent;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainForm)
};