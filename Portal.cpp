#include "Portal.h"





void Portal::animate()
{
	int max = static_cast<int>(timer->get_max_time().asSeconds());
	int elapsed_time = static_cast<int>(timer->get_elapsed_time().asSeconds());
	if (max == elapsed_time)
	{
		if (current_rate != 3)
		{
			current_rate++;
		}
		else {
			current_rate = 1;
		}
	}
	if (current_rate == 1)
	{
		set_image("images/portal/portal1.png");
	}
	else if (current_rate == 2)
	{
		set_image("images/portal/portal2.png");
	}
	else if (current_rate == 3)
	{
		set_image("images/portal/portal3.png");
	}
}
void Portal::react(void* obj_type, void* object, b2World* & world)
{
	check_is_intersected_by(obj_type, world);
	animate();
	
	if (intersected)
	{
		b2Vec2 start_position =  static_cast<Hero*>(object)->get_start_position();
		static_cast<Hero*>(object)->get_body()->SetTransform(start_position, 0.0);
	}
}

Portal::Portal(int half_width,
	           int half_height,
	           float32 density,
	           b2BodyType type,
	           b2World* & world,
	           void* user_data):Trigger(half_width,half_height,density,type,world,user_data)
{
	timer = new Timer(0.4f);
	current_rate = 1;
	body->SetActive(true);
}


Portal::~Portal()
{
	delete timer;
}
