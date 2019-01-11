#pragma once
#include "core\Circle_entity.h"
#include"core/Timer.h"
class Monster :
	public Circle_entity
{
private:
	int direction;

	int detection_radius;
	void set_animation_rate(int rate);
	void intersects_border(b2World* & world);
public:

	void shoot();
	void search_enemy();
	
	void move(b2World* & world);

	void check_is_shot_down(void* bullet_type, b2World* & world);
	void die(b2World* & world);



	Monster(float half_radius,
		    float32 density,
		    b2BodyType type,
		    b2World* & world,
		    void* user_data);
	~Monster();
};

