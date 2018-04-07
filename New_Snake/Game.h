#pragma once

#include "Field.h"
#include "Outputs.h"
#include "Snake.h"

class Game
{
public:
	Game();
	~Game();
	void Start();

private:
	bool running;
	Field My_Field;
	Snake My_Snake;
	size_t Coll_num;
	size_t Field_W;
	size_t Field_H;
	size_t Snake_L;

	void Init();
	void Ongoing();
	void Update();
	void Finish();
	void Restart();
};