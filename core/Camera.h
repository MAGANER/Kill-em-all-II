#pragma once
#include"stdafx.h"
class Camera
{
private:
	View view;

	int z;
public:
	void set_center(float x, float y);
	void move(string direction);
	void move(string direction, float speed);
	void reset(float width, float height);

	void zoom();
	View get_view();
	Camera();
	~Camera();
};

