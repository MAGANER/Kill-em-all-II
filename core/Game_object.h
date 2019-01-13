#pragma once
#include<string>
using namespace std;

class Game_object
{
protected:
	int id;
	string type;
	bool destroy;
public:
	int get_id();
	void set_id(int id);

	string get_type();
	void set_type(string type);
	bool should_be_destroyed();

	Game_object();
	virtual ~Game_object();
};

