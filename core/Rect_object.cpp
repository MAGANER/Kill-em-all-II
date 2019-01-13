#include "Rect_object.h"


Rect_object::Rect_object(int half_width, int half_height, float32 density, b2BodyType type,b2World* & world)
{
	//create physical part only
	//user can load graphical part from file
	shape.SetAsBox(half_width / SCALE, half_height / SCALE);
	body_definition.type = type;
	body_definition.position.Set(get_x() / SCALE, get_y() / SCALE);
	body = world->CreateBody(&body_definition);
	body->CreateFixture(&shape, density);
}
Rect_object::Rect_object(int half_width, int half_height, float32 density, b2World* & world, string image, float x, float y)
{
	//create graphical part
	set_image(image);
	set_pos(x, y);

	//create physical part
	shape.SetAsBox(half_width / SCALE, half_height / SCALE);
	body_definition.position.Set(get_x() / SCALE, get_y() / SCALE);
	body = world->CreateBody(&body_definition);
	body->CreateFixture(&shape, density);
}
Rect_object::Rect_object(int half_width, int half_height, float32 density, b2BodyType type, b2World* & world, string image, float x, float y)
{
	//create graphical part
	set_image(image);
	set_pos(x, y);

	//create physical part
	shape.SetAsBox(half_width / SCALE, half_height / SCALE);
	body_definition.position.Set(get_x() / SCALE, get_y() / SCALE);
	body_definition.type = type;
	body = world->CreateBody(&body_definition);
	body->CreateFixture(&shape, density);
}

Rect_object::~Rect_object()
{
}
