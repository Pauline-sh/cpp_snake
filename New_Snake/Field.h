#pragma once

#include<vector> // for Map containg
#include<iostream>

#include "Snake.h"

/*
EMPTY -- blank cell, can be walke through
SNAKE -- cell contains part of the snake, walking through causes defeat
BORDER -- border cell, can't be walked through
FRUIT -- cell contains collectable, walking through causes score enlargement
STONE -- cell contains stone, can't be walked // not implemented yet
*/

enum OBJ { EMPTY, SNAKE, BORDER, FRUIT, STONE };

enum RESULT { NOTHING, GROW, SHRINK, DIE};

class Field
{
private:
	size_t Height;
	size_t Width;
	std::vector<OBJ> Map;
	size_t Collectables;

public:
	Field(const size_t W = 40, const size_t H = 20);
	~Field();

	void set_Height(size_t H);
	size_t get_Height();

	void set_Width(size_t W);
	size_t get_Width();

	void Field::set_Collectables(size_t C);
	size_t Field::get_Collectables();

	std::vector<OBJ> get_Map();

	void create_Collectables(size_t coll_number = 5, bool rand = true);
	void place_Snake(Snake My_Snake);
	bool move_Snake(Snake My_Snake, Coords Old_Tail, RESULT& action);
	RESULT check(Snake My_Snake);
	void reset();
};