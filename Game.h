#pragma once
#include"core\Rect_entity.h"
#include"core\Circle_entity.h"
#include"WindoW.h"
#include"mySerialisator.h"
#include"Hero.h"
#include"core\Camera.h"
#include"core\Trigger.h"
#include"LevelCounter.h"
#include"Death_screen.h"
#include"core/Bullet.h"
#include"core/Timer.h"
#include"Monster.h"
#include"SFML\Audio.hpp"

class Game
{
private:
	WindoW* window;
	Camera camera;

	b2Vec2 gravity;
	b2World* world;

	Hero* hero;


	Timer* timer;

	mySerialisator serialisator;

	vector<Rect_entity*> plarforms;
	vector<Trigger*> triggers;
	vector<Graphical_object*> background;
	vector<Monster*> monsters;

	LevelCounter* level_counter;

	Death_screen* death_screen;

	vector<Bullet*> bullets;


	bool switch_music;
	bool start_playing;
	Music* hell_music1;
	Music* forest_music1;

	bool give_speed; // when it's sixth level game is little bit slow
private:
	void manage_bullets();

	void check_objects_to_destroy();
	void clear_world();
	void check_triggers_react();
	void check_pressed_key();
	void update_world();
	void draw();

	void play_music();

	b2Vec2 get_spawn_position();
private:
	bool GAME; // if true, than run game
	bool DEATH_SCREEN; // if true, than game = false, and so show game over screen
public: 
	void run();
	
    
 	Game();
	~Game();
};

