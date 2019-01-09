#pragma once
#include"Hero.h"
#include"LevelCounter.h"
class Death_screen
{
private:
	Text you_died,
		restart;

	Font font;

	Vector2f pos;
public:

	void get_pos(Hero* & hero);
	Text get_you_died();
	Text get_restart();

	void check_pressed_keys(bool & GAME, bool & DEATH_SCREEN, Hero* & hero, LevelCounter *& lvl_counter );

	Death_screen(Hero *&hero);
	~Death_screen();
};

