#pragma once
#include"core\Rect_entity.h"
#include"core\WindoW.h"

class Game
{
private:
	WindoW* window;


	b2Vec2 gravity;
	b2World* world;

	void update_world();
	void draw();
public: 
	void run();
	
    
 	Game();
	~Game();
};

