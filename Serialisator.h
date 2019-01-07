#pragma once
#include"json.hpp"
#include<vector>

using namespace std;
using nlohmann::json;

class Serialisator
{
protected:
	json world;
public:
	virtual void serialisate(vector<void*>& objects)   = 0;
	virtual void deserialisate(vector<void*>& objects) = 0;

	Serialisator();
	virtual ~Serialisator();
};

