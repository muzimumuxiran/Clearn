#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("***************************\n");
	printf("*********1.play************\n");
	printf("*********0.out*************\n");
	printf("***************************\n");
}
void game() {
	//�洢�׵���Ϣ
	//1.�����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.ɨ���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	
	//ɨ��
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