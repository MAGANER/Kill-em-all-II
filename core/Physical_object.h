#pragma once
#include<Box2D\Box2D.h>
#include"physical_constants.h"
class Physical_object
{
protected:
	b2BodyDef body_definition;
	b2Body * body;
public:
	b2Body * get_body();
	Physical_object();
	virtual ~Physical_object();
};

