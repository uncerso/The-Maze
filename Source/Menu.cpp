#include "Menu.h"

void Menu::addSeparatorLines() {
	nextSeparatorLines.push_back(static_cast<int>(components.size()));
}

void Menu::paint(Graphics & g) {
	Rectangle<int> separatorLine(7, 0, getWidth() - 14, 2);

	g.setColour(findColour(Label::textColourId).withAlpha(0.4f));

	for (auto & upShift : heightsToDrawSeparatorLines) {
		separatorLine.setY(upShift);
		g.fillRect(separatorLine);
	}
}

void Menu::resized() {
	int upShift = 0;
	const int width = getWidth();
	const int height = static_cast<int>(getHeight() * 0.05);
	constexpr int groupShiftSeparator = 30;

	heightsToDrawSeparatorLines.resize(nextSeparatorLines.size());

	int pos = 0, gropuCounter = 0;
	auto lineUpdater = [this, &upShift, &pos, &gropuCounter, &groupShiftSeparator] {
		while (pos < nextSeparatorLines.size() && nextSeparatorLines[pos] == gropuCounter) {
			heightsToDrawSeparatorLines[pos++] = upShift + groupShiftSeparator / 2 - 1;
			upShift += groupShiftSeparator;
		};
	};

	lineUpdater();
	for (auto & group : components) {
		auto widthElementInGroup = static_cast<int>(width / group.size());
		auto leftShift = 0;
		for (auto & unit : group) {
			unit->setBounds(leftShift, upShift, widthElementInGroup, height);
			leftShift += widthElementInGroup;
		}
		++gropuCounter;
		upShift += height;
		lineUpdater();
	}
}
