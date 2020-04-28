#pragma once
#ifndef _WALL_HEAD_H_
#define _WALL_HEAD_H_

#include <iostream>
using namespace std;

class WALL
{
public:
	enum { ROW = 26, COL = 26 };

	/** ��ʼ��ǽ */
	void initWall();
	/** ����ǽ */
	void drawWall();
	/** �������� */
	void setWall(int x, int y, char c);
	/** ��ȡ���� */
	char getWall(int x, int y);

private:
	char wall[ROW][COL];
};

#endif // !_WALL_HEAD_H_
