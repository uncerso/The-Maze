#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>

class Menu
	: public Component
{
public:
	Menu() = default;

	void paint(Graphics & g) override;
	void resized() override;

	template <class ...T>
	void addGroup(T && ... args);

	void addSeparatorLines();

private:
	std::vector<std::vector<std::unique_ptr<Component> > > components;
	std::vector<int> nextSeparatorLines;
	std::vector<int> heightsToDrawSeparatorLines;
};

template <class ...T>
inline void Menu::addGroup(T && ... args) {
	(addAndMakeVisible(args.get()), ...);
	std::vector<std::unique_ptr<Component> > a;
	(a.emplace_back(std::forward<T>(args)), ...);
	components.emplace_back(std::move(a));
}
