#include "Lever.h"


void Lever::react(void* obj_type, void* object, b2World* & world)
{
	check_is_intersected_by(obj_type, world);

	if (intersected && !activated)
	{
		activated = true;
		set_image("images/lever2.png");

		int access_count = static_cast<Hero*>(object)->get_main_portal_access_counter();
		static_cast<Hero*>(object)->set_access_to_main_portal(access_count + 1);
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
