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

	// �ڵ�
	struct Point
	{
		// ������
		int x;
		int y;

		// ָ����
		Point *next;
	};

	// ��ʼ��
	void initSnake();
	// ���ٽ��
	void destoryPoint();
	// ���ӽ��
	void addPoint(int x, int y);
	// ɾ�����
	void delPoint();

	// �ߵ��ƶ�
	bool move(char key);

	// �趨�Ѷ�
	// ��ȡˢ��ʱ��
	int getSleepTime();
	// ��ȡ�����
	int countList();
	// ��ȡ����
	int getScore();

	Point *pHead;

	WALL &wall;
	Food &food;
	bool isRool;   // �ж�ѭ����ʶ
};

#endif // !_SNAKE_HEAD_H_

