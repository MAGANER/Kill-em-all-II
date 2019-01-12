#pragma once
#include "core\Trigger.h"
#include"core/Timer.h"
#include"Hero.h"
class Portal :
	public Trigger
{
private:
	Timer * timer;
	int current_rate;
public:
	void react(void* obj_type, void* object, b2World* & world);
	void animate();

	Portal(int half_width,
		int half_height,
		float32 density,
		b2BodyType type,
		b2World* & world,
		void* user_data);
	~Portal();
};

