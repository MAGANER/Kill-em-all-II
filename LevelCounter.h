#pragma once
class LevelCounter
{
private:
	int level_counter;
	bool load_next;
public:
	LevelCounter()
	{
		level_counter = 1;
		load_next = false;
	}
	void increase_level()
	{
		++level_counter;
	}
	int get_level()
	{
		return level_counter;
	}
	void set_level(int level_number)
	{
		level_counter = level_number;
	}
	void load_level()
	{
		load_next = true;
	}
	void level_is_loaded()
	{
		load_next = false;
	}
	bool get_state()
	{
		return load_next;
	}
};