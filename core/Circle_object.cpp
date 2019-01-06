#include "Circle_object.h"



Circle_object::Circle_object(float half_radius, int density, b2World* & world, string image, float x, float y)
{
	//create graphical part
	set_image(image);
	set_pos(x, y);

	// create physical part
	shape.m_radius = 32.0f / SCALE;
	body_definition.position.Set(get_x() / SCALE, get_y() / SCALE);
	body = world->CreateBody(&body_definition);
	body->CreateFixture(&shape, density);
}
Circle_object::Circle_object(float half_radius, int density, b2BodyType type, b2World* & world, string image, float x, float y)
{
	//create graphical part
	set_image(image);
	set_pos(x, y);

	//create physical part
	shape.m_radius = 32.0f / SCALE;
	body_definition.type = type;
	body_definition.position.Set(get_x() / SCALE, get_y() / SCALE);
	body = world->CreateBody(&body_definition);
	body->CreateFixture(&shape, density);
}

Circle_object::~Circle_object()
{
}
