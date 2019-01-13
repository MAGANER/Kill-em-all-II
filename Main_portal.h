#pragma once
#include "core\Trigger.h"
#include"Hero.h"
#include"Level_portal.h"
class Main_portal :
	public Trigger
{
private:
	void animate();

	Timer * timer;
	int current_rate;
	int acess_count;
public:
	void react(void* obj_type, void* object, b2World* & world);

	Main_portal(int half_width,
		        int half_height,
		        float32 density,
		        b2BodyType type,
		        b2World* & world,
		        void* user_data);
	~Main_portal();
};

