#include "Death_screen.h"


void Death_screen::get_pos(Hero* & hero)
{
	you_died.setPosition(Vector2f(hero->get_body()->GetPosition().x*SCALE - 450.0f,
		                          hero->get_body()->GetPosition().y*SCALE - 300.0f));

	restart.setPosition(Vector2f(hero->get_body()->GetPosition().x*SCALE - 450.0f,
		hero->get_body()->GetPosition().y*SCALE + 100.0f));
}
Text Death_screen::get_restart()
{
	return restart;
}
Text Death_screen::get_you_died()
{
	return you_died;
}
Death_screen::Death_screen(Hero *&hero)
{
	font.loadFromFile("9303.ttf");

	you_died.setString("YOU DIED AS SHIT");
	you_died.setFont(font);
	you_died.setCharacterSize(90);
	you_died.setFillColor(Color(112, 31, 31, 255));
	//you_died.setPosition(340, 10);

	restart.setString("press SPACE to ressurect");
	restart.setFont(font);
	restart.setCharacterSize(64);
	restart.setFillColor(Color(112, 31, 31, 255));
	//restart.setPosition(420, 200);

	get_pos(hero);
}
void Death_screen::check_pressed_keys(bool & GAME, bool & DEATH_SCREEN, Hero* & hero, LevelCounter *& lvl_counter)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{	
		if (lvl_counter->get_level() == 1)
		{
			hero->get_body()->SetTransform(b2Vec2(3.0f, 1.0f), 0.0f);
			hero->set_health(3);
		}
		if (lvl_counter->get_level() == 2
		|| lvl_counter->get_level() == 3)
		{
			hero->set_health(3);
			hero->get_body()->SetTransform(b2Vec2(0.0f, 0.0f), 0.0f);
		}
		if (lvl_counter->get_level() == 4)
		{
			hero->set_health(3);
			hero->get_body()->SetTransform(b2Vec2(8.0f, 5.0f), 0.0f);
		}

		GAME = true;
		DEATH_SCREEN = false;
	}
}

Death_screen::~Death_screen()
{
}
