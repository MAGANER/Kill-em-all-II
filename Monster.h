#pragma once
#include "core\Circle_entity.h"
class Monster :
	public Circle_entity
{
private:
	int way_length;
	int detection_radius;

	void set_animation_rate(int rate);
public:

	void shoot();
	void move_left();
	void move_right();
	void search_enemy();

	Monster(float half_radius,
		    float32 density,
		    b2BodyType type,
		    b2World* & world,
		    void* user_data);
	~Monster();
};

