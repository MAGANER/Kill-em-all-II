#include "Gun.h"



Gun::Gun(int half_width,
	     int half_height,
	     float32 density,
	     b2BodyType type,
	     b2World* & world,
	     void* user_data):Trigger(half_width,half_height,density,type,world,user_data)
{
}
void Gun::react(void* obj_type, void* object, b2World* & world)
{
	check_is_intersected_by(obj_type, world);
	if (intersected)
	{
		int current_ammo = static_cast<Hero*>(object)->get_ammo();
		static_cast<Hero*>(object)->set_ammo(current_ammo+3);

		destroy = true;
	}
}

Gun::~Gun()
{
}
