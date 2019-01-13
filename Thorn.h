#pragma once
#include "core\Trigger.h"
#include"Hero.h"
#include"core\Timer.h"
class Thorn :
	public Trigger
{
public:
	void react(void* obj_type, void* object, b2World* & world);
	Thorn(int half_width,
		  int half_height,
		  float32 density,
		  b2BodyType type,
		  b2World* & world,
		  void* user_data);
	~Thorn();
};

