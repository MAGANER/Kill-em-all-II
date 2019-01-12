#include "Lever.h"


void Lever::react(void* obj_type, void* object, b2World* & world)
{
	check_is_intersected_by(obj_type, world);

	if (intersected && !activated)
	{
		activated = true;
		set_image("images/lever2.png");
	}
}


Lever::Lever(int half_width,
	         int half_height,
	         float32 density,
	         b2BodyType type,
	         b2World* & world,
	         void* user_data):Trigger(half_width,half_height,density,type,world,user_data)
{
	activated = false;
}


Lever::~Lever()
{
}
