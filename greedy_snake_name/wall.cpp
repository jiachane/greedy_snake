#include "wall.h"

//��ʼ��ǽ
void WALL::initWall()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				wall[i][j] = '*';
			}
			else
			{
				wall[i][j] = ' ';
			}
		}
	}
}

//����ǽ
void WALL::drawWall()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			cout << wall[i][j] << " ";
		}

		if (i == 5) cout << " create by Cheng";
		if (i == 6) cout << " w-->up";
		if (i == 7) cout << " s-->down";
		if (i == 8) cout << " a-->left";
		if (i == 9) cout << " d-->right";
		cout << endl;
	}
}

//��������
void WALL::setWall(int x, int y, char c)
{
	wall[x][y] = c;
}

//��ȡ����
char WALL::getWall(int x, int y)
{
	return wall[x][y];
}
