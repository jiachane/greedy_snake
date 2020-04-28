#pragma once
#ifndef _WALL_HEAD_H_
#define _WALL_HEAD_H_

#include <iostream>
using namespace std;

class WALL
{
public:
	enum { ROW = 26, COL = 26 };

	/** 初始化墙 */
	void initWall();
	/** 绘制墙 */
	void drawWall();
	/** 设置内容 */
	void setWall(int x, int y, char c);
	/** 获取内容 */
	char getWall(int x, int y);

private:
	char wall[ROW][COL];
};

#endif // !_WALL_HEAD_H_
