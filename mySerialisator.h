#pragma once
#include "Serialisator.h"
#include"core\Rect_entity.h"
class mySerialisator :
	public Serialisator
{
public:
	void serialisate(vector<void*>& objects);
	void deserialisate(vector<void*>& objects);

	void deserialisate(vector<Rect_entity*> & objects, b2World* & ph_world, string file_path, bool & done);
	mySerialisator();
	~mySerialisator();
};

