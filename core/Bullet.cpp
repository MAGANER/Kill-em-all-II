#include "Bullet.h"



Bullet::Bullet(float half_radius,
	           float32 density,
	           b2BodyType type,
	           b2World* & world,
	           string image,
	           float x,
	           float y,
	           void* user_data,
	           string flying_direction):Circle_entity(half_radius,density,type,world,image,x,y,user_data)
{
	this->flying_direction = flying_direction;
	collided = false;

	existance_timer = new Timer(1.0f);
}

void Bullet::check_time_till_selfdestruction(b2World* & world)
{
	existance_timer->tic();

	if (existance_timer->get_elapsed_time().asSeconds() >= existance_timer->get_max_time().asSeconds())
	{
		destroy = true;
		world->DestroyBody(body);
	}
}
void Bullet::fly()
{
	if (flying_direction == "left")
	{
		body->ApplyLinearImpulseToCenter(b2Vec2(-0.8f, -0.1f), true);
		//body->SetLinearVelocity(b2Vec2(-0.8f, 0.0f));
	}
	if (flying_direction == "right")
	{
		body->ApplyLinearImpulseToCenter(b2Vec2(0.8f, -0.1f), true);
		//body->SetLinearVelocity(b2Vec2(0.8f, 0.0f));
	}
}
Bullet::~Bullet()
{
	delete existance_timer;
}
