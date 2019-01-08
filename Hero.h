#pragma once
#include "core\Circle_entity.h"
class Hero :
	public Circle_entity
{
private:
	bool on_ground;

	
	void set_animation_rate();
public:
	Hero(float half_radius,
		float32 density,
		b2BodyType type,
		b2World* & world,
		string image,
		float x,
		float y,
		void* user_data);

	void move_right();
	void move_left();

	void jump();

	bool stands_on_ground();

	void check_stands_on_ground();

	~Hero();
};

