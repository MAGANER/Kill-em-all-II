#pragma once
#include"core\Trigger.h"
#include"Hero.h"
class Pusher : public Trigger
{
private:
	string pushing_direction;
public:
	void react(void* obj_type, void* object, b2World* & world);
	Pusher(int half_width,
		   int half_height,
		   float32 density,
		   b2BodyType type,
		   b2World* & world,
		   void* user_data,
		   string pushing_direction);
	~Pusher();
};

