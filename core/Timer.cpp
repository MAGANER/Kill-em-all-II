#include "Timer.h"



Timer::Timer(float max_seconds)
{
	max = seconds(max_seconds);
}

void Timer::tic()
{
	elapsed = clock.getElapsedTime();
	if (elapsed > max)
	{
		clock.restart();
	}
}
Time Timer::get_elapsed_time()
{
	return elapsed;
}
Time Timer::get_max_time()
{
	return max;
}
Timer::~Timer()
{
}
