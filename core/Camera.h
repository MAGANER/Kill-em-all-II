#pragma once
#include"stdafx.h"
class Camera
{
private:
	View view;
public:
	void set_center(float x, float y);
	void move(string direction);
	void move(string direction, float speed);
	void reset(int width, int height);
	View get_view();
	Camera();
	~Camera();
};

