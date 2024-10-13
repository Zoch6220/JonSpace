#pragma once
#include"GlobalVariable.h"
#include <utility>
#include <vector>
struct Bullet
{
	bool death;


	float _x;
	float _y;
	float step_x;
	float step_y;

	short x;
	short y;
	std::vector<short> old_x;
	std::vector<short> old_y;


	Bullet(float p_step_x, float p_step_y, short p_x, short p_y);

	void update();

};

