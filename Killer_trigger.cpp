#include "Killer_trigger.h"



Killer_trigger::Killer_trigger(int half_width,
	                           int half_height,
	                           float32 density,
	                           b2BodyType type,
	                           b2World* & world,
	                           void* user_data):Trigger(half_width,half_height,density,type,world,user_data)
{
}
void Killer_trigger::react(void* obj_type, void* object, b2World* & world)
{
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		if (it->GetUserData() == obj_type)
		{
			b2Vec2 hero_position = static_cast<Hero*>(object)->get_body()->GetPosition();

			bool hero_is_under_trigger = hero_position.y > body->GetPosition().y;
			check_is_intersected_by(obj_type, world);

			if (intersected || hero_is_under_trigger)
			{
				cout << "hero dies" << endl;
				//static_cast<Hero*>(object).set
			}
		}
	}
}

Killer_trigger::~Killer_trigger()
{
}
