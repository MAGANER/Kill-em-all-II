#pragma once
#include"SFML\System.hpp"

using namespace sf;
class Timer
{
private:
	Clock clock;
	Time elapsed;
	Time max;
public:
	void tic();
	Time get_elapsed_time();
	Time get_max_time();
	Timer(float max_seconds);
	~Timer();
};

