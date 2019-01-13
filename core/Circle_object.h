#pragma once
#include"Graphical_object.h"
#include"Physical_object.h"




class Circle_object : public Graphical_object, public Physical_object
{
protected:
	b2CircleShape shape;
public:
	Circle_object(float half_radius, float32 density, b2BodyType type,b2World* & world);
	Circle_object(float half_radius, float32 density, b2World* & world, string image, float x, float y);
	Circle_object(float half_radius, float32 density, b2BodyType type, b2World* & world, string image, float x, float y);
	virtual ~Circle_object();
};

