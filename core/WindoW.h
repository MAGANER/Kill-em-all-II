#pragma once
#include"stdafx.h"
#include"Rect_entity.h"
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
	void clear();
	void display();
	void resize(int width, int height);
	void set_view(View & view);

	void set_frame_rate_limit(unsigned int frame_limit);

	void draw(Rect_entity * & entity);

	WindoW(int width, int height, string title);
	~WindoW();
};

