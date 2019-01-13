#include "Main_portal.h"



void Main_portal::animate()
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
		set_image("images/main portal/active_main_portal1.png");
	}
	else if (current_rate == 2)
	{
		set_image("images/main portal/active_main_portal2.png");
	}
	else if (current_rate == 3)
	{
		set_image("images/main portal/active_main_portal3.png");
	}
}
void Main_portal::react(void* obj_type, void* object, b2World* & world)
{	
	int acess_count = static_cast<Hero*>(object)->get_main_portal_access_counter();
	if (acess_count == 0)
		{
			set_image("images/main portal/non_active_main_portal1.png");
		}
	if (acess_count == 1)
		{
			set_image("images/main portal/non_active_main_portal2.png");
		}
	if (acess_count == 2)
		{
		set_image("images/main portal/non_active_main_portal3.png");
		}
	if (acess_count == 3)
		{
	    animate();
		}
	
	
}


Main_portal::Main_portal(int half_width,
	                     int half_height,
	                     float32 density,
	                     b2BodyType type,
	                     b2World* & world,
	                     void* user_data):Trigger(half_width,half_height,density,type,world,user_data)
{
	timer = new Timer(0.4f);
	current_rate = 1;
	acess_count = 0;

	body->SetActive(true);
}
Main_portal::~Main_portal()
{
	delete timer;
}
