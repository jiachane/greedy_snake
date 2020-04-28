#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>

void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;   // ������
	pos.Y = y;   // ������
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);   //������ʾ���������


int main()
{
	srand((unsigned int)time(NULL));
	WALL wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();
	
	Snake snake(wall, food);
	snake.initSnake();
	//snake.delPoint();

	//snake.move('w');
	//snake.move('w');
	//snake.move('a');

	
	gotoxy(hOut, 0, WALL::ROW);
	cout << "�÷�Ϊ��" << snake.getScore() << endl;

	//gotoxy(hOut, 14, 5); //2*y  // ��ʾ�����ʱ����˿ո�

	bool isDead = false; // �ж��Ƿ�����
	char preKey = NULL;  // ��һ�ΰ���


	while (!isDead)
	{
		// �����û�����
		char key = _getch();

		// ����ǵ�һ�ΰ����������������Ϸ
		// ��¼ǰһ�εİ���
		if (preKey == NULL && key == snake.LEFT) continue;

		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)  //ֻ����wasd�����ְ���
			{
				if ((key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.LEFT && preKey == snake.RIGHT))
				{
					key = preKey;   // ��ͻ������ִ����һ�ΰ�������
				}
				else
				{
					preKey = key;    // ���ǳ�ͻ�����͸�����һ�ΰ�������
				}

				if (snake.move(key))
				{
					// �ƶ��ɹ�����
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, WALL::ROW);
					cout << "�÷�Ϊ��" << snake.getScore() << endl;
					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;
			}
	
		} while (!_kbhit());   // ��û�м��������ʱ�򷵻�0	
	}
	


	//wall.setWall(5, 6, '=');
	//wall.setWall(5, 7, '=');
	//wall.setWall(5, 8, '=');
	//wall.setWall(5, 9, '@');

	//cout<< wall.getWall(5, 6);

	return 0;
}