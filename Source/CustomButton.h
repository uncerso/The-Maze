#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

template<class T>
class CustomButton
	: public T
	, private T::Listener
{
public:
	CustomButton();
	~CustomButton() = default;

	template<class U>
	//func has type std::function<void(Button *)>
	void setCallback(U && func);

private:
	std::function<void(Button *)> funcCallback;

	void buttonClicked(Button * button) override;
};

template<class T>
template<class U>
inline void CustomButton<T>::setCallback(U && func) {
	funcCallback = std::forward<U>(func);
}

template<class T>
inline CustomButton<T>::CustomButton()
	: funcCallback([](Button *) {})
{
	addListener(this);
}

template<class T>
inline void CustomButton<T>::buttonClicked(Button * button) {
	funcCallback(button);
}