#include "Game.h"



Game::Game()
{
	GAME = true;
	DEATH_SCREEN = false;
	level_counter = new LevelCounter;



	timer = new Timer(60.0f);

	window = new WindoW(640,640, "mad rider");
	camera.reset(1280, 720);


	gravity.Set(0.0f, 2.6f);
	world = new b2World(gravity);

	hero = new Hero(32, 1, b2_dynamicBody, world, "images/full_killer_tileset.png", 100.0f, 200.0f, "hero");

	give_speed = false;


	switch_music = false;
	start_playing = false;
	forest_music1 = new Music;
	forest_music1->openFromFile("sounds/forest.ogg");

	hell_music1 = new Music;
	hell_music1->openFromFile("sounds/hell.ogg");
	
}
Game::~Game()
{
	delete world;
	delete window;
	delete timer;
	delete hell_music1;
	delete forest_music1;
}


void Game::manage_bullets()
{
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		bullets[i]->check_time_till_selfdestruction(world);
		bullets[i]->fly();
		bullets[i]->check_collided_anyone(hero,  world);
	}
}
void Game::check_objects_to_destroy()
{
	for (size_t i = 0; i < triggers.size(); ++i)
	{
		if (triggers[i]->should_be_destroyed())
		{
			triggers.erase(triggers.begin() + i);
		}
	}
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->should_be_destroyed())
		{
			bullets.erase(bullets.begin() + i);
		}
	}
	for (size_t i = 0; i < monsters.size(); ++i)
	{
		if (monsters[i]->should_be_destroyed())
		{
		    //if monsters is shot down
			monsters[i]->die(world);
		    monsters.erase(monsters.begin() + i);
		}
	}
}
void Game::clear_world()
{
	plarforms.clear();
	triggers.clear();
	background.clear();
	bullets.clear();
	monsters.clear();

	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		if (it->GetUserData() != hero->get_body()->GetUserData())
		{
			world->DestroyBody(it);
		}
	}
}
void Game::check_triggers_react()
{
	for (size_t i = 0; i < triggers.size(); ++i)
	{
		if (triggers[i]->get_type() == "lvl_portal")
		{
			int y = (int)hero->get_body()->GetLinearVelocity().y;
			if (y == 0)
			{
				triggers[i]->react(hero->get_body()->GetUserData(), level_counter, world);
			}
			if (level_counter->get_state())
			{
				clear_world();

				int level = level_counter->get_level();
				serialisator.deserialisate(plarforms, triggers, background,monsters ,world, "levels/"+to_string(level)+".json", GAME);

				if (level_counter->get_level() != 4)
				{
					hero->get_body()->SetTransform(b2Vec2(0.0f, 0.0f), 0.0f);
				}
				else if (level_counter->get_level() == 4)
				{
					hero->get_body()->SetTransform(b2Vec2(8.0f, 5.0f), 0.0f);
				}
				else if (level_counter->get_level() == 5)
				{
					hero->get_body()->SetTransform(b2Vec2(9.0f, 7.0f), 0.0f);
				}
				else if (level_counter->get_level() == 6)
				{
					//doesn't work. why?
					hero->get_body()->SetTransform(b2Vec2(12.0f, -2.0f), 0.0f);

					b2Vec2 start_position = b2Vec2(12.0f, -2.0f); // it's needed for teleporting
					hero->set_start_position(start_position);

				}
				level_counter->level_is_loaded();
				
			}
		}
		if (triggers[i]->get_type() == "end")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero, world);
		}
		if (triggers[i]->get_type() == "r_trigger")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero, world);
		}
		if (triggers[i]->get_type() == "potion")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero, world);
		}
		if (triggers[i]->get_type() == "gun")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero, world);
		}
		if (triggers[i]->get_type() == "thorn")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero,world);
		}
		if (triggers[i]->get_type() == "lever")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero, world);
		}
		if (triggers[i]->get_type() == "portal")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero, world);
		}
		if (triggers[i]->get_type() == "main_portal")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), hero, world);
		}
		if (triggers[i]->get_type() == "start_portal_new")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), level_counter, world);
			if (level_counter->get_state())
			{
				int level = level_counter->get_level();

				clear_world();
				serialisator.deserialisate(plarforms, triggers, background, monsters, world, "levels/" + to_string(level) + ".json", GAME);
			}
		}
		if (triggers[i]->get_type() == "start_portal_old")
		{
			triggers[i]->react(hero->get_body()->GetUserData(), level_counter, world);
			if (level_counter->get_state())
			{
				int level = level_counter->get_level();

				clear_world();
				serialisator.deserialisate(plarforms, triggers, background, monsters, world, "levels/" + to_string(level) + ".json", GAME);
				hero->get_body()->SetTransform(b2Vec2(0.0f, 0.0f), 0.0f);
			}

		}

	}
}
void Game::check_pressed_key()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		hero->move_left();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		hero->move_right();
	}
		
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		hero->jump();
	}

	if (hero->shoud_shoot())
	{
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			hero->shoot(bullets, world);
			hero->get_right_to_shoot(false);
		}
	}
	if (!Keyboard::isKeyPressed(Keyboard::Q))
	{
		hero->get_right_to_shoot(true);
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window->close();
	}
	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		//camera.zoom();
	}
}
void Game::run()
{
	serialisator.deserialisate(plarforms, triggers,background,monsters ,world, "levels/1.json", GAME);
	while (window->is_open())
	{
		window->check_event();

		if (GAME)
		{	
			check_pressed_key();
			update_world();			
			play_music();
		}
		if (DEATH_SCREEN)
		{
			//clear world than reload and set start hero parameters
			clear_world();

			death_screen->check_pressed_keys(GAME, DEATH_SCREEN,hero, level_counter);
			if (!DEATH_SCREEN)
			{
				delete death_screen;

				string level = "levels/" + to_string(level_counter->get_level()) + ".json";
				serialisator.deserialisate(plarforms, triggers,background,monsters ,world,level,GAME);
				hero->set_health(12);
				hero->set_ammo(0);
				hero->change_rate(2);

				if (level_counter->get_level() >= 6)
				{
					for (size_t i = 0; i < monsters.size(); ++i)
					{
						monsters[i]->give_speed(4.2f);
					}
				}
			}
		}
		
		check_objects_to_destroy();



		draw();
	}
}
void Game::draw()
{
	window->set_view(camera.get_view());

	camera.set_center(hero->get_x(),hero->get_y());

	if (GAME)
	{
		if (level_counter->get_level() == 1)
		{
			window->clear(sf::Color::Black);
		}
		if (level_counter->get_level() < 5 && level_counter->get_level() != 1)
		{
			window->clear(sf::Color::White);
		}
		else {
			window->clear(sf::Color::Black);
		}
		

		hero->set_animation_rate();
		window->draw(background);
		window->draw(hero->returnSprite());
		window->draw(monsters);
		window->draw(plarforms);
		window->draw(triggers);
		window->draw(bullets);
	}
	if (DEATH_SCREEN)
	{
		window->clear(sf::Color::Black);
		window->draw(death_screen->get_restart());
		window->draw(death_screen->get_you_died());
	}

	window->display();
}


void Game::update_world()
{
	world->Step(1 / 60.f, 10, 10);
	timer->tic();

	b2Vec2 position = hero->get_body()->GetPosition();
	hero->set_pos(position.x*SCALE, position.y*SCALE);

	//update bullets
	for (size_t i = 0;i< bullets.size(); ++i)
	{
		b2Vec2 position = bullets[i]->get_body()->GetPosition();
		bullets[i]->set_pos(position.x*SCALE, position.y*SCALE);
			
	}

	//update monsters
	for (size_t i = 0; i < monsters.size(); ++i)
	{
		b2Vec2 position = monsters[i]->get_body()->GetPosition();
		monsters[i]->set_pos(position.x*SCALE, position.y*SCALE);


		monsters[i]->move(world);

		b2Vec2 hero_pos = hero->get_body()->GetPosition();
		monsters[i]->search_enemy(hero_pos, bullets, world);
		monsters[i]->check_is_shot_down("hero_bullet", world);
	}

	manage_bullets();
	check_triggers_react();
	hero->check_stands_on_ground();
	hero->check_is_shot_down("monster_bullet", world);
	if (!hero->check_is_alive())
	{
		hero->dont_stand_on_ground();
		GAME = false;
		DEATH_SCREEN = true;
		death_screen = new Death_screen(hero);
	}


	if (level_counter->get_level() == 7 && !give_speed)
	{
		hero->get_body()->SetTransform(b2Vec2(12.0f, -2.0f), 0.0f);
		hero->give_speed(22.0f, 1.0f);
		world->SetGravity(b2Vec2(0.0f, 9.9f));

		for (size_t i = 0; i < monsters.size(); ++i)
		{
			monsters[i]->give_speed(4.2f);
		}

		give_speed = true;
	}

	hero->is_standing_on_main_portal(world, "main_portal");
	if (hero->check_ability_to_teleport_with_main_portal())
	{
		level_counter->increase_level();
		int level = level_counter->get_level();

		clear_world();
		serialisator.deserialisate(plarforms, triggers, background, monsters, world, "levels/" + to_string(level) + ".json", GAME);
		if (level_counter->get_level() == 8)
		{
			hero->teleport_with_main_portal(b2Vec2(3.0f, 1.0f));
		}
		if (level_counter->get_level() == 9)
		{
			world->SetGravity(b2Vec2(0.0f, 2.6f));
			hero->give_speed(25.0f, 0.2f);
			hero->teleport_with_main_portal(b2Vec2(8.0f, 9.0f));
		}
		level_counter->level_is_loaded();
	}

	
}

void Game::play_music()
{
	if (!start_playing && level_counter->get_level() < 4)
	{
		forest_music1->setLoop(true);
		forest_music1->play();
		start_playing = true;
	}
	if (!start_playing && level_counter->get_level() > 4)
	{
		hell_music1->setLoop(true);
		hell_music1->play();
		start_playing = true;
	}
	if (!switch_music && start_playing && level_counter->get_level() > 4)
	{
		forest_music1->stop();
		start_playing = false;
		switch_music = true;
	}
}


