#include "Thorn.h"



Thorn::Thorn(int half_width,
	         int half_height,
	         float32 density,
	         b2BodyType type,
	         b2World* & world,
	         void* user_data):Trigger(half_width,half_height,density,type,world,user_data)
{
	timer = new Timer(0.5f);
}
void Thorn::react(void* obj_type, void* object, b2World* & world)
{
	check_is_intersected_by(obj_type, world);
	
	float32 velocity = static_cast<Hero*>(object)->get_body()->GetLinearVelocity().y;
	if (intersected && velocity == 0)
	{
	   static_cast<Hero*>(object)->set_health(-666);
	}
}


Thorn::~Thorn()
{
}
