#include "Game.h"



Game::Game()
{
	window = new WindoW(640,640, "mad rider");


	gravity.Set(0.0f, 1.7f);
	world = new b2World(gravity);
}
Game::~Game()
{
	delete world;
	delete window;
}


void Game::run()
{
	while (window->is_open())
	{
		window->check_event();

		update_world();

		draw();
	}
}
void Game::draw()
{
	window->clear();

	window->display();
}

void Game::update_world()
{
	world->Step(1 / 60.f, 8, 3);

	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		b2Vec2 position = it->GetPosition();
		
	}
}