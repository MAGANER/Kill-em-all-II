#pragma once
#include "core\Trigger.h"
#include"Monster.h"
class Monster_border :
	public Trigger
{
public:
	Monster_border(int half_width,
		           int half_height,
		           float32 density,
		           b2BodyType type,
		           b2World* & world,
		           void* user_data);
	void react(void* obj_type, void* object, b2World* & world);
	~Monster_border();
};

