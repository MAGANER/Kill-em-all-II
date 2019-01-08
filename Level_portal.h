#pragma once
#include "core/Trigger.h"
#include"LevelCounter.h"
class Level_portal :
	public Trigger
{
public:
	void react(void* obj_type, void* object,b2World* & world);

	Level_portal(int half_width,
		int half_height,
		float32 density,
		b2BodyType type,
		b2World* & world,
		void* user_data);
	~Level_portal();
};

