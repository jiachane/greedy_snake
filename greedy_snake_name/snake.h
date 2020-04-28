#pragma once
#ifndef _SNAKE_HEAD_H_
#define _SNAKE_HEAD_H_

#include <iostream>
#include "wall.h"
#include "food.h"
using namespace std;

class Snake
{
public:
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };
	Snake(WALL &tempwall, Food &tempfood);

	// 节点
	struct Point
	{
		// 数据域
		int x;
		int y;

		// 指针域
		Point *next;
	};

	// 初始化
	void initSnake();
	// 销毁结点
	void destoryPoint();
	// 增加结点
	void addPoint(int x, int y);
	// 删除结点
	void delPoint();

	// 蛇的移动
	bool move(char key);

	// 设定难度
	// 获取刷屏时间
	int getSleepTime();
	// 获取蛇身段
	int countList();
	// 获取分数
	int getScore();

	Point *pHead;

	WALL &wall;
	Food &food;
	bool isRool;   // 判断循环标识
};

#endif // !_SNAKE_HEAD_H_

