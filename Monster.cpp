#include "Monster.h"



Monster::Monster(float half_radius,
	             float32 density,
	             b2BodyType type,
	             b2World* & world,
	             void* user_data) :Circle_entity(half_radius,density,type,world,"monster")
{
	set_animation_rate(1);
	body->SetActive(true);
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
void Monster::move_left()
{
	set_animation_rate(1);
}
void Monster::move_right()
{
	set_animation_rate(2);
}

Monster::~Monster()
{
}
