#pragma once

#include <iostream>
#include "wall.h"
using namespace std;

class Food
{
public:
	Food(WALL &tempwall);

	// …Ë÷√ ≥ŒÔ
	void setFood();

	int FoodX;
	int FoodY;
	WALL &wall;
};
