#include "Trigger.h"


void Trigger::check_is_intersected_by(void* obj_type, b2World* & world)
{
	b2Vec2 trg_pos = body->GetPosition();
	b2Vec2 obj_pos;
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{

		if (it->GetUserData() == obj_type)
		{
			obj_pos = it->GetPosition();
			bool x1 = obj_pos.x + (1 / SCALE) >= trg_pos.x;
			bool x2 = obj_pos.x <= trg_pos.x + (gobject_spr.getTextureRect().width / SCALE);

			bool y1 = obj_pos.y+(1 / SCALE) >= trg_pos.y;
			bool y2 = obj_pos.y <= trg_pos.y + (gobject_spr.getTextureRect().height / SCALE);

			if (x1 && x2 && y1 && y2 )
			{
				intersected = true;
				cout << "intersected" << endl;
			}
			else 
			{
				intersected = false;
			}

		}
	}
}
Trigger::Trigger(int half_width,
	int half_height,
	float32 density,
	b2BodyType type,
	b2World* & world,
	void* user_data) :Rect_entity(half_width, half_height, density, type, world,user_data)
{
	body->SetActive(false);
	intersected = false;
}
Trigger::~Trigger()
{
}
