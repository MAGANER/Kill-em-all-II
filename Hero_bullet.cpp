#include "Hero_bullet.h"



Hero_bullet::Hero_bullet(float half_radius,
	                     float32 density,
	                     b2BodyType type,
	                     b2World* & world,
	                     string image,
	                     float x,
	                     float y,
	                     void* user_data,
	                     string flying_direction):Bullet(half_radius,density,type,world,image,x,y,user_data,flying_direction)
{
}
void Hero_bullet::check_collided_anyone(void* obj_type, b2World* & world)
{

}

Hero_bullet::~Hero_bullet()
{
}
