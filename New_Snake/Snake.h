#pragma once
#include <vector>

#include "Interface_Windows.h"

struct Coords
{
	size_t X;
	size_t Y;
};

class Snake
{
public:
	Snake();
	~Snake();

	size_t get_Length();
	Coords get_Head();
	Coords get_Tail();
	std::vector<Coords> get_Body();

	void set_dir(direction new_dir);
	direction get_dir();

	void init(size_t L, const size_t Map_Width, const size_t Map_Height);
	void move();
	void grow();
	bool shrink();

private:
	size_t Length; // == 1 + body.length()
	Coords Head;
	std::vector<Coords> Body;
	direction cur_dir;	
};