// this is common class of every game object like player, enemy etc
#pragma once
#include"stdafx.h"

class Graphical_object
{
protected:
    float x_pos, y_pos;
	string img_file;

	Image gobject_img;
	Texture gobject_textr;
	Sprite gobject_spr;

public:
	void set_rotation_angle(float angle);
	float get_rotation_angle();

	void set_pos(float x, float y);
	float get_x();
	float get_y();

	void set_image(string img);
	string get_image_path();

	Sprite returnSprite();

	Graphical_object();
	virtual ~Graphical_object();
};

