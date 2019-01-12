#pragma once
#include "core\Trigger.h"
class Lever :
	public Trigger
{
private:
	bool activated;

public:
	void react(void* obj_type, void* object, b2World* & world);

	Lever(int half_width,
		  int half_height,
		  float32 density,
		  b2BodyType type,
		  b2World* & world,
		  void* user_data);
	~Lever();
};

