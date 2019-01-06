#include "Graphical_object.h"

float Graphical_object::get_x()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.x;
}
float Graphical_object::get_y()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.y;
}
void Graphical_object::set_pos(float x, float y)
{
	gobject_spr.setPosition(x, y);
}
Sprite Graphical_object::returnSprite()
{
	return gobject_spr;
}
void Graphical_object::set_image(string img)
{
	img_file = img;
	gobject_img.loadFromFile(img_file);
	gobject_img.createMaskFromColor(Color(255, 255, 255));
	gobject_textr.loadFromImage(gobject_img);
	gobject_spr.setTexture(gobject_textr);

}

Graphical_object::Graphical_object()
{

}

Graphical_object::~Graphical_object()
{
}
