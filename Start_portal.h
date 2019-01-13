#pragma once
#include "core\Trigger.h"
#include"core\Timer.h"
#include"LevelCounter.h"

class Start_portal :
	public Trigger
{
private:
	Timer * timer;
	int current_rate;
public:
	Start_portal(int half_width,
		         int half_height,
		         float32 density,
		         b2BodyType type,
		         b2World* & world,
		         void* user_data);
	void react(void* obj_type, void* object, b2World* & world);

	void animate();
	~Start_portal();
};

