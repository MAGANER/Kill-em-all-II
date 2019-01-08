#pragma once
#include"Rect_entity.h"
#include<Box2D\Box2D.h>
class Trigger : public Rect_entity
{
protected:
	bool intersected;
public:
	void check_is_intersected_by(void* obj_type,b2World* & world);

	virtual void react(void* obj_type,void* object ,b2World* & world) = 0;

	Trigger(int half_width,
		    int half_height,
		    float32 density,
		    b2BodyType type,
		    b2World* & world,
		    void* user_data);
	~Trigger();
};

