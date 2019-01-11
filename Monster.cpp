#include "Monster.h"



Monster::Monster(float half_radius,
	             float32 density,
	             b2BodyType type,
	             b2World* & world,
	             void* user_data) :Circle_entity(half_radius,density,type,world,"monster")
{
	set_animation_rate(2);
	body->SetLinearDamping(1.0f);
	destroy = false;
	detection_radius = 500.0f / SCALE;
	direction = 1;
	can_move = true;

}
void Monster::set_animation_rate(int rate)
{
	if (rate == 1)
	{
		gobject_spr.setTextureRect(IntRect(58, 0, 64, 64));
	}
	if (rate == 2)
	{
		gobject_spr.setTextureRect(IntRect(0, 0, 64, 64));
	}
}


void Monster::check_is_shot_down(void* bullet_type, b2World* & world)
{
	b2Vec2 trg_pos = body->GetPosition();
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		if (it->GetUserData() == bullet_type)
		{
			bool x = (body->GetPosition().x*SCALE) + 32.0f > it->GetPosition().x*SCALE;
			bool y = (body->GetPosition().x*SCALE) + 32.0f < (it->GetPosition().x*SCALE) + 64.0f;
			bool h1 = (body->GetPosition().y*SCALE) <= (it->GetPosition().y*SCALE) + 200.0f;
			bool h2 = (body->GetPosition().y*SCALE) + 32.0f >= it->GetPosition().y*SCALE;

			bool H = h1 && h2;

			if (x && y && H)
			{
				destroy = true;
			}
		}
	}


}
void Monster::die(b2World* & world)
{
	world->DestroyBody(body);
}


void Monster::intersects_border(b2World* & world)
{
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		if (it->GetUserData() == "l_border")
		{
			// x means position of hero when his right side is furhter than trigger left side
			bool x = (body->GetPosition().x*SCALE) + 32.0f > it->GetPosition().x*SCALE;
			bool y = (body->GetPosition().x*SCALE) + 32.0f < (it->GetPosition().x*SCALE) + 64.0f;
			bool h1 = body->GetPosition().y*SCALE <= (it->GetPosition().y*SCALE) + 200.0f;
			bool h2 = (body->GetPosition().y*SCALE) + 32.0f >= it->GetPosition().y*SCALE;
			// H means hero stays on trigger
			bool H = h1 && h2;


			if (x && y && H)
			{
				direction = 2;
			}

		}
		if (it->GetUserData() == "r_border")
		{
			// x means position of hero when his right side is furhter than trigger left side
			bool x = (body->GetPosition().x*SCALE) + 32.0f > it->GetPosition().x*SCALE;
			// y means position of hero when his right side is not further than trigger right side
			bool y = (body->GetPosition().x*SCALE) + 32.0f < (it->GetPosition().x*SCALE) + 64.0f;
			//h1 means position of hero when it is under down side of object
			bool h1 = body->GetPosition().y*SCALE <= (it->GetPosition().y*SCALE) + 200.0f;
			//h2 means position of hero when it is above high side of object
			bool h2 = (body->GetPosition().y*SCALE) + 32.0f >= it->GetPosition().y*SCALE;
			// H means hero stays on trigger
			bool H = h1 && h2;


			if (x && y && H)
			{
				direction = 1;
			}

		}
	}
}
void Monster::move(b2World* & world)
{
	if (can_move)
	{
		intersects_border(world);
		if (direction == 1)
		{
			body->SetLinearVelocity(b2Vec2(-0.3f, 0.0f));
			set_animation_rate(1);
		}
		if (direction == 2)
		{
			body->SetLinearVelocity(b2Vec2(0.3f, 0.0f));
			set_animation_rate(2);
		}
	}
}
void Monster::search_enemy(b2Vec2& hero_pos)
{
	bool on_the_same_land = static_cast<int>(body->GetPosition().y) == static_cast<int>(hero_pos.y);

	if (direction == 2)
	{
		bool see_target = body->GetPosition().x +(64.0f/SCALE) + detection_radius > hero_pos.x;
		bool target_is_righter_me = hero_pos.x > body->GetPosition().x ;

		if (on_the_same_land && see_target && target_is_righter_me)
		{
			cout << "shoot him na hui down!" << endl;
			can_move = false;
		}
		else {
			can_move = true;
		}
	}
	if (direction == 1)
	{
		bool see_target = body->GetPosition().x - detection_radius < hero_pos.x;
		bool target_is_lefter = body->GetPosition().x > hero_pos.x;
		if (on_the_same_land && see_target && target_is_lefter)
		{
			cout << "shoot him na hui down!" << endl;
			can_move = false;
		}
		else {
			can_move = true;
		}
	}
}

Monster::~Monster()
{
}