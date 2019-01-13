#pragma once
#include "core\Circle_entity.h"
#include"Hero_bullet.h"
#include<SFML\Audio.hpp>

class Hero :
	public Circle_entity
{
private:
	SoundBuffer *jump_buffer, *shoot_buffer;
	Sound *jumping, *shooting;

	b2Vec2 start_position;

	float32 walk_speed;
	float32 jump_speed;

	bool on_ground;
	bool _shoot; // set true, if hero can shoot

	int health;
	int ammo;

	int direction; // if 1, set left rate. if 2, set right rate. 
	               // if 3, than hero with gun goes left, if 4, than hero with gun goes right 


	int main_portal_access_counter; // when hero contacts lever increase this variable, it's needed to
	                                // 3 ones to open portal

	bool ready_to_be_teleported_with_main_portal; // when hero has full success, he teleports to next level
	bool stands_on_main_portal;

	
public:
	Hero(float half_radius,
		float32 density,
		b2BodyType type,
		b2World* & world,
		string image,
		float x,
		float y,
		void* user_data);
	
	b2Vec2 get_start_position();
	void set_start_position(b2Vec2 start_position);


	void move_right();
	void move_left();


	void shoot(vector<Bullet*>& bullets, b2World* & world);
	bool shoud_shoot();
	void get_right_to_shoot(bool right);

	void jump();

	bool stands_on_ground();

	void check_stands_on_ground();
	bool check_is_alive();

	void set_ammo(int ammo);
	int get_ammo();

	void set_health(int health);
	int get_health();

	void dont_stand_on_ground();
	
	void set_animation_rate();
	void change_rate(int direction);

	void check_is_shot_down(void* bullet_type, b2World* & world);

	void give_speed(float32 jump_speed, float32 walk_speed);

	int get_main_portal_access_counter();
	void set_access_to_main_portal(int access);
    bool check_ability_to_teleport_with_main_portal();
	void is_standing_on_main_portal(b2World *&world, void* portal_type);
	void teleport_with_main_portal(b2Vec2 position);
	~Hero();
};

