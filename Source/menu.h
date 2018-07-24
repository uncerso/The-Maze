#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Menu 
	: public Component
{
public:
	Menu()
	{	}

	void showOrHide() {
	}

	void paint(Graphics & canvas) {
		canvas.fillAll(Colour::fromRGB(100, 100, 100));
	}

private:
	std::unique_ptr<MenuBarComponent> menuBar;
};