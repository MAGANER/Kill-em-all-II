#include "mySerialisator.h"


void mySerialisator::serialisate(vector<void*>& objects)
{
	
}
void mySerialisator::deserialisate(vector<void*>& objects)
{

}

void mySerialisator::deserialisate(vector<Rect_entity*> & objects, b2World* & ph_world, string file_path, bool & done)
{
	ifstream file;
	
	file.open(file_path);
	if (file.fail())
	{
		cout << "fuck you";
	}
	file >> world;

	int object_counter = 0;
	while (true)
		{
		    if (!world["world"][to_string(object_counter)].empty())
			{
				Rect_entity * object = new Rect_entity(32, 32, 10, b2_staticBody, ph_world, "land");

				cout << "good" << endl;
				int id = object_counter;
				float x = world["world"][to_string(object_counter)].at(0);
				float y = world["world"][to_string(object_counter)].at(1);
				string image = world["world"][to_string(object_counter)].at(2);
				string type = world["world"][to_string(object_counter)].at(3);
				float rotation = world["world"][to_string(object_counter)].at(4);

				b2Vec2 position;

				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() /SCALE;
				position.y = object->get_y() /SCALE;
				object->get_body()->SetTransform(position, rotation);

				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				objects.push_back(object);
				++object_counter;
			}
			else {
				done = true;
				cout << "fuck";
				break;
			}
		}
	
}
mySerialisator::mySerialisator()
{
}


mySerialisator::~mySerialisator()
{
}
