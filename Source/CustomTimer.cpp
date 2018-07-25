#include "CustomTimer.h"

CustomTimer::CustomTimer()
	: funcCallback([]{})
{}

inline void CustomTimer::timerCallback() {
	funcCallback();
}
