#pragma once

#include <iostream>
#include "wall.h"
using namespace std;

class Food
{
public:
	Food(WALL &tempwall);

	// ����ʳ��
	void setFood();

	int FoodX;
	int FoodY;
	WALL &wall;
};
