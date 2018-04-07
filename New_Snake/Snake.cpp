#include "Snake.h"

Snake::Snake()
{
	//construction
}
Snake::~Snake()
{
	// destruction
}

size_t Snake::get_Length()
{
	return Length;
}
Coords Snake::get_Head()
{
	return Head;
}
Coords Snake::get_Tail()
{
	return Body[Body.size() - 1];
}
std::vector<Coords> Snake::get_Body()
{
	return Body;
}

void Snake::set_dir(direction new_dir)
{
	cur_dir = new_dir;
}
direction Snake::get_dir()
{
	return cur_dir;
}

void Snake::init(size_t L, const size_t Map_Width, const size_t Map_Height)
{
	Length = L;
	Body.resize(L - 1);
	cur_dir = RIGHT;

	Head.X = Map_Width / 2;
	Head.Y = Map_Height / 2;
	for (size_t i = 0; i < Body.size(); i++)
	{
		Body[i].X = Map_Width / 2 - 1 - i;
		Body[i].Y = Map_Height / 2;
	}
}

void Snake::move()
{
	Coords prev_coords = Head;
	Coords buf;
	for (size_t i = 0; i < Body.size(); i++)
	{
		buf = Body[i];
		Body[i] = prev_coords;
		prev_coords = buf;
	}

	switch (cur_dir)
	{
	case TOP:
		Head.Y--;
		break;
	case RIGHT:
		Head.X++;
		break;
	case BOTTOM:
		Head.Y++;
		break;
	case LEFT:
		Head.X--;
		break;
	}
}
void Snake::grow()
{
	Length++;
	Coords last = Body[Body.size() - 1];
	Coords prelast = Body[Body.size() - 2];
	Coords buf;

	if ((last.X == prelast.X) && (last.Y == (prelast.Y - 1))) // TOP
	{
		buf.X = last.X;
		buf.Y = last.Y + 1;
	}
	else if ((last.Y == prelast.Y) && (last.X == (prelast.X + 1))) // RIGHT
	{
		buf.X = last.X - 1;
		buf.Y = last.Y;
	}
	else if ((last.X == prelast.X) && (last.Y == (prelast.Y + 1))) // BOTTOM
	{
		buf.X = last.X;
		buf.Y = last.Y - 1;
	}
	else if ((last.Y == prelast.Y) && (last.X == (prelast.X - 1))) // LEFT
	{
		buf.X = last.X + 1;
		buf.Y = last.Y;
	}
	Body.push_back(buf);
}
bool Snake::shrink()
{
	Length--;
	if (Body.size() == 1)
		return false;
	Body.pop_back();
	return true;
}