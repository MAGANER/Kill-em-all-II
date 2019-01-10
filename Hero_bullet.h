#pragma once
#include "core/Bullet.h"
class Hero_bullet :
	public Bullet
{
public:
	Hero_bullet(float half_radius,
		        float32 density,
	 	        b2BodyType type,
		        b2World* & world,
		        string image,
		        float x,
		        float y,
		        void* user_data,
		        string flying_direction);

	void check_collided_anyone(void* obj_type,b2World* & world);
	~Hero_bullet();
};

