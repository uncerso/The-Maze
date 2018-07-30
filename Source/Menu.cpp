#include "Menu.h"

void Menu::paint(Graphics &g) {

}

void Menu::resized() {
	constexpr int leftShifts = 0;
	int upShifts = 0;
	const int width = getWidth();
	const int height = getHeight() * 0.05;
	constexpr int groupShiftSeparator = 15;

	for (auto & group : components) {
		for (auto & unit : group) {
			unit->setBounds(leftShifts, upShifts, width, height);
			upShifts += height;
		}
		upShifts += groupShiftSeparator;
	}
}