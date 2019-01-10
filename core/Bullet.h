#pragma once
#include "Circle_entity.h"
#include"Timer.h"
class Bullet :
	public Circle_entity
{
private:
	Timer* existance_timer;
protected:
	string flying_direction;
	bool collided;
public:
	Bullet(float half_radius,
		   float32 density,
		   b2BodyType type,
		   b2World* & world,
		   string image,
		   float x,
		   float y,
		   void* user_data,
		   string flying_direction);

	void fly();
	void check_time_till_selfdestruction(b2World* & world);
	virtual void check_collided_anyone(void* obj_type,b2World* & world) =0;
	virtual ~Bullet();
};

