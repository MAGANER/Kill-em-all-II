#pragma once
#include"Rect_object.h"
#include"Game_object.h"

#include<iostream>
class Rect_entity: public Rect_object, public Game_object
{
public:
	Rect_entity(int half_width,
		       int half_height,
		       int density,
		       b2BodyType type,
		       b2World* & world,
		       string image,
		       float x,
		       float y);
	Rect_entity(int half_width,
		int half_height,
		int density,
		b2BodyType type,
		b2World* & world,
		string image,
		float x,
		float y,
		void* user_data);

	virtual ~Rect_entity();

    
	void update();
};

