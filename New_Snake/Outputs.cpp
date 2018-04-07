#include "Outputs.h"

/*
EMPTY -- blank cell, can be walke through
SNAKE -- cell contains part of the snake, walking through causes defeat
BORDER -- border cell, can't be walked through
FRUIT -- cell contains collectable, walking through causes score enlargement
STONE -- cell contains stone, can't be walked // not implemented yet
*/

void Outputs::print_Field(Field Current_Field)
{
	std::vector<OBJ> Cur_Map = Current_Field.get_Map();
	size_t Field_Width = Current_Field.get_Width();
	size_t Field_Height = Current_Field.get_Height();
	const size_t border_indent = 1;

	for (size_t i = border_indent; i < Field_Height - border_indent; i++)
	{
		Interface_Win::set_Cursor(1, i);
		for (size_t j = border_indent; j < Field_Width - border_indent; j++)
		{
			OBJ Cell = Cur_Map[i * Field_Width + j];
			switch (Cell)
			{
			case EMPTY:
				std::cout << " ";
				break;
			case SNAKE:
				std::cout << "o";
				break;
			case FRUIT:
				std::cout << "@";
				break;
			case STONE:
				std::cout << "+";
				break;
			}
		}
		if(i != Field_Height - border_indent - 1)
			std::cout << std::endl;
	}
	Interface_Win::hide_Cursor();
}

void Outputs::print_Borders(Field Current_Field)
{
	size_t Field_Width = Current_Field.get_Width();
	size_t Field_Height = Current_Field.get_Height();

	for (size_t i = 0; i < Field_Height; i++)
	{
		for (size_t j = 0; j < Field_Width; j++)
		{
			if ((i == 0) || (i == Field_Height - 1) || (j == 0) || (j == Field_Width - 1))
			{
				std::cout << "*";
				if (j == Field_Width - 1)
					std::cout << "\n";
			}
			else
				std::cout << " ";
		}
	}
	Interface_Win::hide_Cursor();
}

void Outputs::print_Debug(Field Current_Field, Snake Cur_Snake)
{
	size_t Field_Height = Current_Field.get_Height();
	Coords Head = Cur_Snake.get_Head();
	Coords Tail = Cur_Snake.get_Tail();
	direction cur_dir = Cur_Snake.get_dir();
	size_t Cur_Coll_num = Current_Field.get_Collectables();

	Interface_Win::set_Cursor(0, Field_Height);
	std::cout << "Head.X = " << Head.X << std::endl << "Head.Y = " << Head.Y << std::endl
		<< "Tail.X = " << Tail.X << std::endl << "Tail.Y = " << Tail.Y << std::endl
		<< "Length = " << Cur_Snake.get_Length() << std::endl
		<< "Cur_direction = " << cur_dir << std::endl
		<< "Cur_Coll_num == " << Cur_Coll_num << std::endl;
}

void Outputs::print_FinalScreen(Field Current_Field, Snake Cur_Snake)
{
	Sleep(1000);
	Interface_Win::clear_Screen();
	size_t Score = Cur_Snake.get_Length() - 3;

	Interface_Win::set_Cursor(Current_Field.get_Width() / 2 - strlen("Game over!") / 2, Current_Field.get_Height() / 2 - 1);
	std::cout << "Game over!" << std::endl;
	Interface_Win::set_Cursor(Current_Field.get_Width() / 2 - strlen("Your score   ") / 2, Current_Field.get_Height() / 2);
	std::cout << "Your score: " << Score << std::endl;	
}

bool Outputs::if_Restart(Field Current_Field)
{
	Interface_Win::set_Cursor(Current_Field.get_Width() / 2 - strlen("Wanna play another round? Yes == 1, No == 2") / 2, Current_Field.get_Height() / 2 + 1);
	std::cout << "Wanna play another round? Yes == 1, No == 2 ";

	int answ = 0;
	std::cin >> answ;
	if (answ == 1)
	{
		Interface_Win::clear_Screen();
		return true;
	}
	Interface_Win::hide_Cursor();
	return false;
}
