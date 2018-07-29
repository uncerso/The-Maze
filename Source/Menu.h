#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Menu
	: public Component
{
public:
	Menu() {


	}

	void paint(Graphics & /*canvas*/) override {
	}

	void resized() override {
	}

private:
	std::unique_ptr<MenuBarComponent> menuBar;
};