#include "Interface_Windows.h"

direction Interface_Win::get_direction(direction cur_dir)
{
	int key = _getch();
	switch (key)
	{
		case 119: // TOP
			if (cur_dir != BOTTOM)
				cur_dir = TOP;
			break;
		case 100: // RIGHT
			if (cur_dir != LEFT)
				cur_dir = RIGHT;
			break;
		case 115: // BOTTOM
			if (cur_dir != TOP)
				cur_dir = BOTTOM;
			break;
		case 97: // LEFT
			if (cur_dir != RIGHT)
				cur_dir = LEFT;
			break;
		default:
			break;
	}
	return cur_dir;
	/* // не работает на клавишах со стрелками
	if ((key == 97) || (key == 228)) // LEFT
	{
		if (cur_dir != RIGHT)
			cur_dir = LEFT;
	}
	else if ((key == 100) || (key == 162)) // RIGHT
	{
		if (cur_dir != LEFT)
			cur_dir = RIGHT;
	}
	else if ((key == 115) || (key == 235)) // BOTTOM
	{
		if (cur_dir != TOP)
			cur_dir = BOTTOM;
	}
	else if ((key == 119) || (key == 230)) // TOP
	{
		if (cur_dir != BOTTOM)
			cur_dir = TOP;
	}
	return cur_dir;
	*/
}

void Interface_Win::set_Cursor(size_t Xc, size_t Yc)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cPos;
	cPos.X = Xc;
	cPos.Y = Yc;
	SetConsoleCursorPosition(hCon, cPos);
}

void Interface_Win::hide_Cursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

void Interface_Win::clear_Screen()
{
	system("cls");
}

void Interface_Win::pause_for(const size_t milliseconds)
{
	Sleep(milliseconds);
}