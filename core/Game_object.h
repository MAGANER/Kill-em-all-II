#pragma once
#include<string>
using namespace std;

class Game_object
{
protected:
	int id;
	string type;
public:
	int get_id();
	void set_id(int id);

	string get_type();
	void set_type(string type);

	virtual void update() = 0;
	 
	Game_object();
	virtual ~Game_object();
};

