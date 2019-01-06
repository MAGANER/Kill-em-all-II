#include "Camera.h"




void Camera::set_center(float x, float y)
{
	view.setCenter(x, y);
}

void Camera::move(string direction)
{
	if (direction == "up")
	{
		view.move(0.0f, -0.1f);
	}
	if (direction == "left")
	{
		view.move(-0.5f, 0.0f);
	}
	if (direction == "right")
	{
		view.move(0.5f, 0.0f);
	}
	if (direction == "down")
	{
		view.move(0.0f, 0.1f);
	}
}
void Camera::move(string direction, float speed)
{
	if (direction == "up")
	{
		view.move(0.0f, -speed);
	}
	if (direction == "left")
	{
		view.move(-speed, 0.0f);
	}
	if (direction == "right")
	{
		view.move(speed, 0.0f);
	}
	if (direction == "down")
	{
		view.move(0.0f, speed);
	}
}
void Camera::reset(int width, int height)
{
	view.reset(FloatRect(0.0f, 0.0f, width, height));
}
View Camera::get_view()
{
	return view;
}
Camera::Camera()
{

}


Camera::~Camera()
{
}
