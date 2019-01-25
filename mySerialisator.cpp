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
void mySerialisator::deserialisate(vector<Rect_entity*> & objects,
	                               vector<Trigger*>& triggers,
	                               vector<Graphical_object*>& background,
	                               vector<Monster*>& monsters,
	                               b2World* & ph_world, string file_path, bool & done)
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
			int id = object_counter;
			float x = world["world"][to_string(object_counter)].at(0);
			float y = world["world"][to_string(object_counter)].at(1);
			string image = world["world"][to_string(object_counter)].at(2);
			string type = world["world"][to_string(object_counter)].at(3);
			float rotation = world["world"][to_string(object_counter)].at(4);

			if (type != "end"
				&& type != "lvl_portal"
				&& type != "final"
				&& type != "tree"
				&& type != "r_trigger"
				&& type != "potion"
				&& type != "l_border"
				&& type != "r_border"
				&& type != "gun"
				&& type != "tak"
				&& type != "thorn"
				&& type != "lever"
				&& type != "portal"
				&& type != "main_portal"
				&& type != "start_portal_new"
				&& type != "start_portal_old"
				&& type != "start")
			{
				// tak == monster
				cout << type << endl;
				Rect_entity * object = new Rect_entity(32, 32, 10, b2_staticBody, ph_world, "land");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);

				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				objects.push_back(object);
				++object_counter;
			}	
			if (type == "gun")
			{
				Gun * object = new Gun(42, 42, 1, b2_staticBody, ph_world, "gun");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				triggers.push_back(object);

				++object_counter;
			}
			if (type == "potion")
			{
				Health_potion * object = new Health_potion(42, 42, 1, b2_staticBody, ph_world, "potion");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				triggers.push_back(object);
				++object_counter;
			}
			if (type == "r_trigger")
			{
				Pusher * object = new Pusher(32, 32, 1, b2_staticBody, ph_world, "r_trigger", "right");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				triggers.push_back(object);
				++object_counter;
			}
			if (type == "lvl_portal")
				{	
				Level_portal* object = new Level_portal(32, 32, 1.0f, b2_staticBody, ph_world, "lvl_portal");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				triggers.push_back(object);
				++object_counter;
				}
			if (type == "end")
			{
				Killer_trigger* object = new Killer_trigger(32, 32, 1, b2_staticBody, ph_world, "end");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				triggers.push_back(object);
				++object_counter;
			}
			if (type == "final" || type == "tree")
			{
				Graphical_object * object = new Graphical_object;
				object->set_pos(x, y);
				object->set_image(image);
				object->set_rotation_angle(rotation);
				background.push_back(object);
				++object_counter;
			}
			if (type == "l_border")
			{
				cout << "LB" << endl;
				Monster_border* object = new Monster_border(32, 32, 1.0f, b2_staticBody, ph_world, "l_border");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				triggers.push_back(object);
				++object_counter;
			}
			if (type == "r_border")
			{
				cout << "RB" << endl;
				Monster_border* object = new Monster_border(32, 32, 1.0f, b2_staticBody, ph_world, "r_border");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);

				triggers.push_back(object);
				++object_counter;
			}
			if (type == "tak")
			{
				Monster * object = new Monster(32, 5, b2_dynamicBody, ph_world, "monster");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				monsters.push_back(object);

				++object_counter;
			}
			if (type == "thorn")
			{
				Thorn * object = new Thorn(32,10, 2.0f, b2_staticBody, ph_world, "thorn");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				triggers.push_back(object);

				++object_counter;
			}
			if (type == "lever")
			{
				Lever * object = new Lever(32, 10, 2, b2_staticBody, ph_world, "lever");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				triggers.push_back(object);

				++object_counter;
			}
			if (type == "portal")
			{
				Portal * object = new Portal(20, 5, 2, b2_staticBody, ph_world, "portal");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				triggers.push_back(object);

				++object_counter;
			}
			if (type == "main_portal")
			{
				Main_portal * object = new Main_portal(20, 5, 2, b2_staticBody, ph_world, "main_portal");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				triggers.push_back(object);

				++object_counter;
			}
			if (type == "start_portal_old")
			{
				Start_portal * object = new Start_portal(20, 5, 2, b2_staticBody, ph_world, "old");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				triggers.push_back(object);

				++object_counter;
			}
			if (type == "start_portal_new")
			{
				Start_portal * object = new Start_portal(20, 5, 2, b2_staticBody, ph_world, "new");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				triggers.push_back(object);

				++object_counter;
			}
			if (type == "start")
			{
				Start * object = new Start(32, 32, 1, b2_staticBody, ph_world, "start");
				b2Vec2 position;
				object->set_pos(x, y);

				// we must give give position to body, cos
				// this constructor creates only physical part
				// but physical part gets data to set position
				// from graphical one

				position.x = object->get_x() / SCALE;
				position.y = object->get_y() / SCALE;
				object->get_body()->SetTransform(position, rotation);
				object->set_id(id);
				object->set_image(image);
				object->set_type(type);
				object->set_rotation_angle(rotation);
				triggers.push_back(object);

				++object_counter;
			}
		}
		else {
			done = true;
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
