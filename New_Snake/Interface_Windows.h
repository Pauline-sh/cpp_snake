#pragma once
#include <conio.h>
#include <windows.h>

enum direction { TOP, RIGHT, BOTTOM, LEFT };

class Interface_Win
{
public:
	static direction get_direction(direction cur_dir);

	static void set_Cursor(const size_t Xc, const size_t Yc);

	static void hide_Cursor();

	static void clear_Screen();

	static void pause_for(const size_t milliseconds);
};