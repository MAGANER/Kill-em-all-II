#include "Start.h"




void Start::react(void* obj_type, void* object, b2World* & world)
{
	static_cast<Hero*>(object)->get_body()->SetTransform(body->GetPosition(), 0.0f);
}
Start::Start(int half_width,
	         int half_height,
          	 float32 density,
	         b2BodyType type,
	         b2World* & world,
	         void* user_data) :Trigger(half_width, half_height, density, type, world, user_data)
{
}


Start::~Start()
{
}
