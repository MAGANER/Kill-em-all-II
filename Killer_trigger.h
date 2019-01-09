#pragma once
#include "core\Trigger.h"
#include"Hero.h"

class Killer_trigger :
	public Trigger
{
public:
	void react(void* obj_type, void* object, b2World* & world);

	Killer_trigger(int half_width,
		           int half_height,
		           float32 density,
		           b2BodyType type,
		           b2World* & world,
		           void* user_data);
	~Killer_trigger();
};

