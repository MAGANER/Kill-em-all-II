#include "Circle_entity.h"



Circle_entity::Circle_entity(float half_radius,
	                         float32 density,
	                         b2BodyType type,
	                         b2World* & world,
	                         string image,
	                         float x,
	                         float y):Circle_object(half_radius,density,type,world,image,x,y)
{
}
Circle_entity::Circle_entity(float half_radius,
	                         float32 density,
	                         b2BodyType type,
                             b2World* & world,
	                         string image,
	                         float x,
	                         float y,
	                         void* user_data):Circle_object(half_radius, density, type, world, image, x, y)
{
	body->SetUserData(user_data);
}
Circle_entity::Circle_entity(float half_radius,
	                         float32 density,
	                         b2BodyType type,
	                         b2World* & world,
	                         void* user_data):Circle_object(half_radius, density, type, world)
{
	body->SetUserData(user_data);
}
Circle_entity::~Circle_entity()
{
}



