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

	on_ground = false;
}

void Hero::move_right()
{
	body->ApplyLinearImpulseToCenter(b2Vec2(0.2f, 0.0f), true);
}
void Hero::move_left()
{
	body->ApplyLinearImpulseToCenter(b2Vec2(-0.2f, 0.0f), true);
}


void Hero::jump()
{
	if (on_ground)
	{
		body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -20.0f), true);
	}
}


bool Hero::stands_on_ground()
{
	return on_ground;
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
						cout << "check" << endl;
						on_ground = true;
						break;
					}
				}
				{
					cout << "fuck" << endl;
					on_ground = false;
				}
			}
		}
	}
}

Hero::~Hero()
{
}
