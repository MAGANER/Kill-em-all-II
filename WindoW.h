#pragma once
#include"core/stdafx.h"
#include"core/Rect_entity.h"
#include"core/Circle_entity.h"
#include"core/Trigger.h"
#include"core/Bullet.h"
#include"Monster.h"
#include"Thorn.h"

class WindoW
{
private:
	RenderWindow win;
	VideoMode size;
	string title;
public:
	
	bool is_open();
	void check_event();

	void create();
	void close();
	void clear(sf::Color color);
	void clear();
	void display();
	void resize(int width, int height);
	void set_view(View & view);

	void set_frame_rate_limit(unsigned int frame_limit);

	void draw(Sprite & sprite);
	void draw(Circle_entity * & entity);
	void draw(Rect_entity * & entity);
	void draw(vector<Rect_entity*> & objects);
	void draw(vector<Trigger *>& triggers);
	void draw(vector<Graphical_object*>& backrgound);
	void draw(Text & text);
	void draw(vector<Bullet*>& bullets);
	void draw(vector<Monster*>& monsters);

	WindoW(int width, int height, string title);
	~WindoW();
};

