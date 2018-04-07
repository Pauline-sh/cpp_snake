#pragma once

#include<vector>
#include<string>
#include<iostream>

#include "Collectable.h"
#include "Field.h"
#include "Snake.h"
#include "Interface_Windows.h"

/*
EMPTY -- blank cell, can be walke through
SNAKE -- cell contains part of the snake, walking through causes defeat
BORDER -- border cell, can't be walked through
FRUIT -- cell contains collectable, walking through causes score enlargement
STONE -- cell contains stone, can't be walked // not implemented yet
*/

class Outputs
{
public:
	static void print_Field(Field Current_Field);

	static void print_Borders(Field Current_Field);

	static void print_Debug(Field Current_Field, Snake Cur_Snake);

	static void print_FinalScreen(Field Current_Field, Snake Cur_Snake);

	static bool if_Restart(Field Current_Field);
};