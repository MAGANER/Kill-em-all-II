#include "Game_object.h"


void Game_object::set_id(int id)
{
	this->id = id;
}
int Game_object::get_id()
{
	return id;
}

void Game_object::set_type(string type)
{
	this->type = type;
}
string Game_object::get_type()
{
	return type;
}

bool Game_object::should_be_destroyed()
{
	return destroy;
}
Game_object::Game_object()
{
	destroy = false;
}


Game_object::~Game_object()
{
}
