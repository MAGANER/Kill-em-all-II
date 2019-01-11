#include "Monster_border.h"



Monster_border::Monster_border(int half_width,
	int half_height,
	float32 density,
	b2BodyType type,
	b2World* & world,
	void* user_data) :Trigger(half_width, half_height,density,type,world,user_data)
{
}
void Monster_border::react(void* obj_type, void* object, b2World* & world)
{

}

Monster_border::~Monster_border()
{
}
