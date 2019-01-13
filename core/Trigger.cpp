#include "Trigger.h"


void Trigger::check_is_intersected_by(void* obj_type, b2World* & world)
{
	b2Vec2 trg_pos = body->GetPosition();
	//b2Vec2 obj_pos;
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		if (it->GetUserData() == obj_type)
		{
			/*
			obj_pos = it->GetPosition();
			bool x1 = obj_pos.x + (1 / SCALE) >= trg_pos.x;
			bool x2 = obj_pos.x <= trg_pos.x + (gobject_spr.getTextureRect().width / SCALE);

			bool y1 = obj_pos.y+(1 / SCALE) >= trg_pos.y;
			bool y2 = obj_pos.y <= trg_pos.y + (gobject_spr.getTextureRect().height / SCALE);
			*/
			bool x = (body->GetPosition().x*SCALE) + 32.0f > it->GetPosition().x*SCALE;
			bool y = (body->GetPosition().x*SCALE) + 32.0f < (it->GetPosition().x*SCALE) + 64.0f;
			bool h1 = (body->GetPosition().y*SCALE) <= (it->GetPosition().y*SCALE) + 200.0f;
			bool h2 = (body->GetPosition().y*SCALE) + 32.0f >= it->GetPosition().y*SCALE;

			bool H = h1 && h2;
		
			if (x && y && H )
			{
				intersected = true;
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
