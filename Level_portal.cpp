#include "Level_portal.h"



void Level_portal::react(void* obj_type, void* object, b2World* & world)
{
	check_is_intersected_by(obj_type, world);
	if (intersected)
	{
		static_cast<LevelCounter*>(object)->increase_level();
		static_cast<LevelCounter*>(object)->load_level();
    }
}

Level_portal::Level_portal(int half_width,
	int half_height,
	float32 density,
	b2BodyType type,
	b2World* & world,
	void* user_data) :Trigger(half_width, half_height, density, type, world,user_data)
{
}


Level_portal::~Level_portal()
{
}
