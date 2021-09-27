#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("***************************\n");
	printf("*********1.play************\n");
	printf("*********0.out*************\n");
	printf("***************************\n");
}
void game() {
	//存储雷的信息
	//1.布置雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.扫出雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	
	//扫雷
	FineMine(mine, show, ROW, COL);
	
}
void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("please choose:\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("game out!\n");
			break;
		default:
			printf("choose wrong!please choose another!\n");
			break;
		}
	} while (input);
}
int main() {

	test();
	return 0;
}