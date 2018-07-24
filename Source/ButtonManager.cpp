#include "ButtonManager.h"

class : public Button::Listener{
public:
	void buttonClicked(Button * button) override {
		// 'button' calls 'buttonClicked' <=> 'links' contains 'button'
		links.find(button)->second();
	}

	void addLink(Button * button, std::function<void()> const & function) {
		button->addListener(this);
		links[button] = function;
	}

	void removeLink(Button * button) {
		button->removeListener(this);
		links.erase(button);
	}

private:
	std::unordered_map<Button *, std::function<void()> > links;
} buttonManagerHandle;

void ButtonManager::addLink(Button * button, std::function<void()> const &function) {
	buttonManagerHandle.addLink(button, function);
}

void ButtonManager::removeLink(Button * button) {
	buttonManagerHandle.removeLink(button);
}