#include "Game.h"
#include "Interface_Windows.h" // conio.h contains kbhit()

Game::Game()
{

}

Game::~Game()
{

}

void Game::Start()
{
	Init();
	Ongoing();
}

void Game::Ongoing()
{
	Outputs::print_Borders(My_Field);
	Outputs::print_Field(My_Field);
	Outputs::print_Debug(My_Field, My_Snake);

	while (running)
	{
		Update();
		if((My_Snake.get_dir() == RIGHT) || (My_Snake.get_dir() == LEFT))
			Interface_Win::pause_for(150);
		else
			Interface_Win::pause_for(200);
		Outputs::print_Field(My_Field);
		Outputs::print_Debug(My_Field, My_Snake);
	}
	Interface_Win::pause_for(1000);
	Finish();
}

void Game::Init()
{
	running = true;
	Coll_num = 5;
	Field_W = 40;
	Field_H = 20;
	Snake_L = 3;

	My_Field = Field(Field_W, Field_H);
	My_Snake = Snake();

	My_Snake.init(Snake_L, Field_W, Field_H);
	My_Field.place_Snake(My_Snake);

	My_Field.create_Collectables(Coll_num);
}

void Game::Update()
{
	if (_kbhit()) // wasd
	{
		My_Snake.set_dir(Interface_Win::get_direction(My_Snake.get_dir()));
	}
	Coords Old_Tail = My_Snake.get_Tail();
	My_Snake.move();

	RESULT action = NOTHING;
	running = My_Field.move_Snake(My_Snake, Old_Tail, action);
	if (action == GROW)
	{
		My_Snake.grow();
		size_t Cur_Coll_num = My_Field.get_Collectables();
		My_Field.set_Collectables(Cur_Coll_num - 1);
		if (Cur_Coll_num - 1 == 0)
		{
			My_Field.create_Collectables(Coll_num);
			My_Field.set_Collectables(Coll_num);
		}			
	}
}

void Game::Finish()
{
	Outputs::print_FinalScreen(My_Field, My_Snake);
	bool wanna_restart = Outputs::if_Restart(My_Field);
	if (wanna_restart)
		Restart();
	else
		Interface_Win::clear_Screen();
}

void Game::Restart()
{
	My_Field.reset();
	My_Field.create_Collectables(Coll_num);

	My_Snake.init(Snake_L, Field_W, Field_H);
	My_Field.place_Snake(My_Snake);
	running = true;
	Ongoing();
}