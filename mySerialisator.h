#pragma once
#include "Serialisator.h"
#include"core\Rect_entity.h"
#include"Level_portal.h"
#include"Killer_trigger.h"
#include"Pusher.h"
#include"Health_potion.h"
#include"Gun.h"
#include"Monster.h"
#include"Monster_border.h"
#include"Thorn.h"
#include"Lever.h"
#include"Portal.h"
#include"Main_portal.h"
#include"Start_portal.h"
class mySerialisator :
	public Serialisator
{
public:
	void serialisate(vector<void*>& objects);
	void deserialisate(vector<void*>& objects);

	void deserialisate(vector<Rect_entity*> & objects, b2World* & ph_world, string file_path, bool & done);
	void deserialisate(vector<Rect_entity*> & objects,
		               vector<Trigger*>& triggers,
		               vector<Graphical_object*>& background,
		               vector<Monster*>& monsters,
		               b2World* & ph_world, string file_path, bool & done);
	mySerialisator();
	~mySerialisator();
};

