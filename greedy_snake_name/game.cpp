#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>

void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;   // 横坐标
	pos.Y = y;   // 纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);   //定义显示器句柄变量


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
	cout << "得分为：" << snake.getScore() << endl;

	//gotoxy(hOut, 14, 5); //2*y  // 显示坐标的时候加了空格

	bool isDead = false; // 判断是否死亡
	char preKey = NULL;  // 上一次按键


	while (!isDead)
	{
		// 接收用户输入
		char key = _getch();

		// 如果是第一次按了左键，不激活游戏
		// 记录前一次的按键
		if (preKey == NULL && key == snake.LEFT) continue;

		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)  //只允许wasd这四种按键
			{
				if ((key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.LEFT && preKey == snake.RIGHT))
				{
					key = preKey;   // 冲突按键就执行上一次按键内容
				}
				else
				{
					preKey = key;    // 不是冲突按键就更新上一次按键内容
				}

				if (snake.move(key))
				{
					// 移动成功代码
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, WALL::ROW);
					cout << "得分为：" << snake.getScore() << endl;
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
	
		} while (!_kbhit());   // 当没有键盘输入的时候返回0	
	}
	


	//wall.setWall(5, 6, '=');
	//wall.setWall(5, 7, '=');
	//wall.setWall(5, 8, '=');
	//wall.setWall(5, 9, '@');

	//cout<< wall.getWall(5, 6);

	return 0;
}