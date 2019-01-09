#include "Health_potion.h"




void Health_potion::react(void* obj_type, void* object, b2World* & world)
{
	check_is_intersected_by(obj_type, world);
    
	if (intersected)
	{
		cout << "take up hp" << endl;

		int current_health = static_cast<Hero*>(object)->get_health();
		static_cast<Hero*>(object)->set_health(current_health + 1);
		cout << static_cast<Hero*>(object)->get_health() << endl;
		destroy = true;

	}
}
Health_potion::Health_potion(int half_width,
	                         int half_height,
	                         float32 density,
	                         b2BodyType type,
	                         b2World* & world,
	                         void* user_data):Trigger(half_width,half_height,density,type,world,user_data)
{
}
Health_potion::~Health_potion()
{
}
