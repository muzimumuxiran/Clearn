#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("***********************\n");
	printf("**1.play  0.exit ******\n");
	printf("***********************\n");
}
void game() {
	char ret = ' ';
	//�洢������Ϣ
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		//��������
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ�ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ��\n");
	}
	else if (ret = 'q')
	{
		printf("ƽ�֣�\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			break;
		}

	} while (input);

}

int main() {

	test();
	return 0;
}