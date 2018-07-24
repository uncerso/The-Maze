#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <unordered_map>
#include "Pair.h"

struct ButtonManager
{
	ButtonManager() = delete;
	static void addLink(Button * button, std::function<void()> const & function);
	static void removeLink(Button * button);
};