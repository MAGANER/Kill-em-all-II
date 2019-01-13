#include "Rect_entity.h"



Rect_entity::Rect_entity(int half_width,
	int half_height,
	float32 density,
	b2BodyType type,
	b2World* & world,
	string image,
	float x,
	float y) :Rect_object(half_width, half_width, density, type, world,image,x,y)
{
	
}
Rect_entity::Rect_entity(int half_width,
	int half_height,
	float32 density,
	b2BodyType type,
	b2World* & world,
	string image,
	float x,
	float y,
	void* user_data) : Rect_object(half_width, half_width, density, type, world, image, x, y)
{
	body->SetUserData(user_data);
}

Rect_entity::Rect_entity(int half_width,
	int half_height,
	float32 density,
	b2BodyType type,
	b2World* & world,
	void* user_data) : Rect_object(half_width, half_width, density, type, world)
{
	body->SetUserData(user_data);
}

Rect_entity::~Rect_entity()
{

}
