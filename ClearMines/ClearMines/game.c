#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			Board[i][j] = set;
		}
	}
}

void DisplayBoard(char Board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <=row; i++) {//打印列号
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);//打印行号
		for (j = 1; j <=col; j++) {
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char Board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (Board[x][y] = '0') {
			Board[x][y] = '1';
			count--;
		}
	}
}
int GetMineCount(char mine[ROWS][COLS],int x,int y){
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT) {
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {//是雷，游戏结束
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				//不是雷，计算周围有几个雷
				int count = GetMineCount(mine,x,y);
				//写入雷的数量
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else {
			printf("坐标非法，请重新输入!\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("恭喜你，扫雷成功！！！\n");
		DisplayBoard(mine, row, col);
		
	}
	
}
