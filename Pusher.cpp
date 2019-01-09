#include "Pusher.h"


void Pusher::react(void* obj_type, void* object, b2World* & world)
{
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{	   
		if (it->GetUserData() == obj_type)
		{
			check_is_intersected_by(obj_type, world);
			if (intersected)
			{
				if (pushing_direction == "left")
				{
					static_cast<Hero*>(object)->get_body()->ApplyForceToCenter(b2Vec2(-500.0f, 0.0f), true);
					
				}
				if (pushing_direction == "right")
				{				
					cout << "shot" << endl;
					static_cast<Hero*>(object)->get_body()->ApplyForceToCenter(b2Vec2(-3500.0f, 0.0f), true);
				}
			}
		}
	}
}
Pusher::Pusher(int half_width,
	           int half_height,
	           float32 density,
	           b2BodyType type,
	           b2World* & world,
	           void* user_data,
	           string pushing_direction):Trigger(half_width,half_height,density,type,world,user_data)
{
	this->pushing_direction = pushing_direction;
}


Pusher::~Pusher()
{
}
