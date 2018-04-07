#include "Field.h"

Field::Field(size_t W, size_t H)
{
	Height = H;
	Width = W;
	size_t size = Height*Width;
	Map.resize(size, EMPTY);
	for(size_t i = 0; i < Width; i++)
	{
		Map[i] = BORDER;
		Map[size - i - 1] = BORDER;
	}
	for (size_t j = 0; j < Height; j++)
	{
		Map[j * Width] = BORDER;
		Map[j * Width + Width - 1] = BORDER;
	}
}
Field::~Field()
{
	// destruction
}

void Field::set_Height(size_t H)
{
	Height = H;
}
size_t Field::get_Height()
{
	return Height;
}

void Field::set_Width(size_t W)
{
	Width = W;
}
size_t Field::get_Width()
{
	return Width;
}

void Field::set_Collectables(size_t C)
{
	Collectables = C;
}
size_t Field::get_Collectables()
{
	return Collectables;
}

std::vector<OBJ> Field::get_Map()
{
	return Map;
}

void Field::create_Collectables(size_t coll_number, bool rand)
{
	Collectables = coll_number;
	if(rand)
		for (size_t i = 0; i < coll_number; i++)
		{
			const size_t border_indent = 2;
			size_t x = std::rand() % (Width - border_indent) + 1;
			size_t y = std::rand() % (Height - border_indent) + 1;

			if (Map[y * Width + x] == SNAKE)
				i--;
			else
				Map[y * Width + x] = FRUIT;
		}
	else
	{
		// implement later
	}
}
void Field::place_Snake(Snake My_Snake)
{
	std::vector<Coords> Body = My_Snake.get_Body();
	Coords Head = My_Snake.get_Head();
	Map[Head.Y * Width + Head.X] = SNAKE;
	for (size_t i = 0; i < Body.size(); i++)
	{
		Map[Body[i].Y * Width + Body[i].X] = SNAKE;
	}
}
bool Field::move_Snake(Snake My_Snake, Coords Old_Tail, RESULT& action)
{
	action = check(My_Snake);
	if (action != DIE)
	{
		Coords Head = My_Snake.get_Head();
		std::vector<Coords> Body = My_Snake.get_Body();

		Map[Head.Y * Width + Head.X] = SNAKE;
		for (size_t i = 0; i < Body.size(); i++)
		{
			Map[Body[i].Y * Width + Body[i].X] = SNAKE;
		}
		Map[Old_Tail.Y * Width + Old_Tail.X] = EMPTY;
		return true;
	}
	else
		return false;
}

RESULT Field::check(Snake My_Snake) // checking lose opportunities
{
	Coords Head = My_Snake.get_Head();
	if ((Map[Head.Y * Width + Head.X] == BORDER) || (Map[Head.Y * Width + Head.X] == SNAKE))
		return DIE;
	else if (Map[Head.Y * Width + Head.X] == FRUIT) // growing check here
		return GROW;
	else
		return NOTHING;
}
void Field::reset()
{
	for (size_t i = 1; i < Height - 1; i++)
		for (size_t j = 1; j < Width - 1; j++)
			if (Map[i*Width + j] = FRUIT)
				Map[i*Width + j] = EMPTY;
}