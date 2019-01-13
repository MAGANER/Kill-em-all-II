#pragma once
#include "core\Circle_entity.h"
#include"core/Timer.h"
#include"core/Bullet.h"
#include"Hero_bullet.h"
#include"SFML\Audio.hpp"
class Monster :
	public Circle_entity
{
private:
	SoundBuffer  *shoot_buffer, *death_buffer;
	Sound  *shooting, *death;


	int direction;
	bool can_move;

	bool see_target;
	bool shot;
	Timer* timer;

	float32 speed;

	int detection_radius;
	void set_animation_rate(int rate);
	void intersects_border(b2World* & world);
	void shoot(vector<Bullet*>& bullets, b2World* & world);
public:
	void search_enemy(b2Vec2& hero_pos, vector<Bullet*>& bullets, b2World* & world);


	void move(b2World* & world);

	void check_is_shot_down(void* bullet_type, b2World* & world);
	void die(b2World* & world);

	void give_speed(float32 speed);

	Monster(float half_radius,
		    float32 density,
		    b2BodyType type,
		    b2World* & world,
		    void* user_data);
	~Monster();
};

