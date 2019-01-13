#pragma once
#include"Graphical_object.h"
#include"Physical_object.h"

class Rect_object : public Graphical_object, public Physical_object
{
private:
	b2PolygonShape shape;
public:
	Rect_object(int half_width, int half_height, float32 density, b2BodyType type,b2World* & world);
	Rect_object(int half_width, int half_height, float32 density,b2World* & world, string image, float x, float y);
	Rect_object(int half_width, int half_height, float32 density,b2BodyType type ,b2World* & world, string image, float x, float y);
	virtual ~Rect_object();
};

