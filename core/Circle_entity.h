#pragma once
#include "Circle_object.h"
#include"Game_object.h"

class Circle_entity :
	public Circle_object, public Game_object
{
public:
	Circle_entity(float half_radius,
		          int density,
		          b2BodyType type,
		          b2World* & world,
		          string image,
		          float x,
		          float y);
	virtual ~Circle_entity();

};

