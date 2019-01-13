#include "Hero.h"
Hero::Hero(float half_radius,
	       float32 density,
	       b2BodyType type,
	       b2World* & world,
 	       string image,
	       float x,
	       float y,
	       void* user_data):Circle_entity(half_radius,density,type,world,image,x,y)
{
	body->SetLinearDamping(2.0f);

	ammo = 0;
	health = 18;
	on_ground = false;

	direction = 2;


	walk_speed = 0.2f;
	jump_speed = 25.0f;


	jump_buffer = new SoundBuffer;
	shoot_buffer = new SoundBuffer;

	jump_buffer->loadFromFile("sounds/jump.ogg");
	shoot_buffer->loadFromFile("sounds/shoot.ogg");

	jumping = new Sound;
	shooting = new Sound;

	jumping->setBuffer(*jump_buffer);
	shooting->setBuffer(*shoot_buffer);

	main_portal_access_counter = 0;
	ready_to_be_teleported_with_main_portal = false;
	stands_on_main_portal = false;
}


b2Vec2 Hero::get_start_position()
{
	return start_position;
}
void Hero::set_start_position(b2Vec2  start_position)
{
	this->start_position = start_position;
}


void Hero::move_right()
{
	if (ammo <= 0)
	{
		direction = 2;
	}
	else {
		direction = 4;
	}
	body->ApplyLinearImpulseToCenter(b2Vec2(walk_speed, 0.0f), true);
}
void Hero::move_left()
{
	if (ammo <= 0)
	{
		direction = 1;
	}
	else {
		direction = 3;
	}
	body->ApplyLinearImpulseToCenter(b2Vec2(-walk_speed, 0.0f), true);
}


void Hero::jump()
{
	if (on_ground)
	{
		jumping->play();
		body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -jump_speed), true);
	}
}


bool Hero::stands_on_ground()
{
	return on_ground;
}
void Hero::dont_stand_on_ground()
{
	on_ground = false;
}
void Hero::check_stands_on_ground()
{
	if (body->GetLinearVelocity().y != 0 || body->GetLinearVelocity().x != 0)
	{
		for (b2ContactEdge* ce = body->GetContactList(); ce; ce = ce->next)
		{
			
			b2Contact* c = ce->contact;
			if (c->GetFixtureA()->GetUserData() == body->GetUserData())
			{

				if (c->IsTouching())
				{
					b2Vec2 hero_bottom;
					hero_bottom.x = body->GetPosition().x;
					hero_bottom.y = body->GetPosition().y + (64 / SCALE);

					if (c->GetFixtureA()->TestPoint(hero_bottom))
					{
						on_ground = true;
						break;
					}
				}
				{
					on_ground = false;
				}
			}
		}
	}
}
bool Hero::check_is_alive()
{
	if (health > 0)
	{
		return 1;
	}
	if (health <= 0)
	{
		return 0;
	}
}

void Hero::set_animation_rate()
{
	if (direction == 1)
	{
		gobject_spr.setTextureRect(IntRect(64, 0, 64, 64));
	}
	if (direction == 2)
	{
		gobject_spr.setTextureRect(IntRect(0, 0, 64, 64));
	}
	if (direction == 3)
	{
		gobject_spr.setTextureRect(IntRect(64, 64, 64, 64));
	}
	if (direction == 4)
	{
		gobject_spr.setTextureRect(IntRect(0, 64, 64, 64));
	}

}
void Hero::change_rate(int rate)
{
	direction = rate;
}
void Hero::set_health(int health)
{
	this->health = health;
}
int Hero::get_health()
{
	return health;
}

void Hero::set_ammo(int ammo)
{
	this->ammo = ammo;
}
int Hero::get_ammo()
{
	return ammo;
}


void Hero::shoot(vector<Bullet*>& bullets, b2World* & world)
{
	shooting->play();
	if (ammo > 0)
	{
		cout << "shoot" << endl;
		string flying_direction;
		float x_bullet_pos, y_bullet_pos = get_y()+30.0f;
		if (direction == 2 || direction == 4)
		{
			flying_direction = "right";
			x_bullet_pos = get_x()+42.0f ;

			// push hero
			body->ApplyLinearImpulseToCenter(b2Vec2(-8.0f, 0.0f), true);
		}
		if (direction == 1 || direction == 3)
		{
			flying_direction = "left";
			x_bullet_pos = get_x()-32.0f;

			// push hero
			body->ApplyLinearImpulseToCenter(b2Vec2(8.0f, 0.0f), true);
		}
		
		Hero_bullet * bullet = new Hero_bullet(2.0f,
			                                   4.0f,
			                                   b2_dynamicBody,
			                                   world,
			                                   "images/bullet.png",
			                                   x_bullet_pos,
			                                   y_bullet_pos, 
			                                   "hero_bullet", 
			                                   flying_direction);

		bullets.push_back(bullet);


		--ammo;
		
	}
	// if hero wasted all ammo change rate
	if (ammo <= 0)
	{
		if (direction == 1)
		{
			change_rate(1);
		}
		if (direction == 2)
		{
			change_rate(2);
		}
	}
}
bool Hero::shoud_shoot()
{
	return _shoot;
}
void Hero::get_right_to_shoot(bool right)
{
	_shoot = right;
}

void Hero::check_is_shot_down(void* bullet_type, b2World* & world)
{
	b2Vec2 trg_pos = body->GetPosition();
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		if (it->GetUserData() == bullet_type)
		{
			bool x = (body->GetPosition().x*SCALE) + 32.0f > it->GetPosition().x*SCALE;
			bool y = (body->GetPosition().x*SCALE) + 32.0f < (it->GetPosition().x*SCALE) + 64.0f;
			bool h1 = (body->GetPosition().y*SCALE) <= (it->GetPosition().y*SCALE) + 200.0f;
			bool h2 = (body->GetPosition().y*SCALE) + 32.0f >= it->GetPosition().y*SCALE;

			bool H = h1 && h2;

			if (x && y && H)
			{
				--health;
			}
			
		}
	}
}


void Hero::give_speed(float32 jump_speed, float32 walk_speed)
{
	this->jump_speed = jump_speed;
	this->walk_speed = walk_speed;
}

int Hero::get_main_portal_access_counter()
{
	return main_portal_access_counter;
}
void Hero::set_access_to_main_portal(int access)
{
	main_portal_access_counter = access;
}
bool Hero::check_ability_to_teleport_with_main_portal()
{
	if (stands_on_main_portal && main_portal_access_counter == 3)
	{
		ready_to_be_teleported_with_main_portal = true;
	}
	return ready_to_be_teleported_with_main_portal;
}
void Hero::is_standing_on_main_portal(b2World *&world, void* portal_type)
{
	for (b2Body* it = world->GetBodyList(); it != 0; it = it->GetNext())
	{
		if (it->GetUserData() == portal_type)
		{
			bool x1 = (body->GetPosition().x*SCALE) + 64.0f > it->GetPosition().x*SCALE;
			bool x2 = (body->GetPosition().x*SCALE) < (it->GetPosition().x*SCALE) + 64.0f;
			bool h1 = (body->GetPosition().y*SCALE) < (it->GetPosition().y*SCALE) ;

			bool between_portal_panel = x1 && x2;

			if (between_portal_panel && h1)
			{
				stands_on_main_portal = true;
			}
			else
			{
				stands_on_main_portal = false;
			}

		}
	}
}
void Hero::teleport_with_main_portal(b2Vec2 position)
{
	body->SetTransform(position, 0.0f);

	stands_on_main_portal = false;
	ready_to_be_teleported_with_main_portal = false;
	main_portal_access_counter = 0;
}

Hero::~Hero()
{
	delete jump_buffer;
	delete shoot_buffer;
	delete jumping;
	delete shooting;
}
