#pragma once
#include "Circle_object.h"
#include"Game_object.h"

class Circle_entity :
	public Circle_object, public Game_object
{
public:
	Circle_entity(float half_radius,
		          float32 density,
		          b2BodyType type,
		          b2World* & world,
		          string image,
		          float x,
		          float y);

	Circle_entity(float half_radius,
		          float32 density,
		          b2BodyType type,
		          b2World* & world,
		          string image,
		          float x,
		          float y,
		          void* user_data);

	Circle_entity(float half_radius,
		          float32 density,
		          b2BodyType type,
		          b2World* & world,
		          void* user_data);


	virtual ~Circle_entity();

};

