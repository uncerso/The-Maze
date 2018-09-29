#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class CustomTimer 
	: public Timer
{
public:
	CustomTimer();
	~CustomTimer() = default;

	template<class T>
	//func has type std::function<void()>
	void setCallback(T && func);
private:
	std::function<void()> funcCallback;

	void timerCallback() override;
};

template<class T>
inline void CustomTimer::setCallback(T && func) {
	funcCallback = std::forward<T>(func);
}