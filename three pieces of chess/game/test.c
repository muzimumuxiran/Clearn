#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("***********************\n");
	printf("**1.play  0.exit ******\n");
	printf("***********************\n");
}
void game() {
	char ret = ' ';
	//存储棋盘信息
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		//电脑下棋
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜！\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜！\n");
	}
	else if (ret = 'q')
	{
		printf("平局！\n");
	}
}
void test() 
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("please input your chose:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择出错,请重新选择\n");
			break;
		}

	} while (input);

}

int main() {

	test();
	return 0;
}