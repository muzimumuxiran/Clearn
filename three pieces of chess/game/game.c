#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//���Ի�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
			{
				printf(" %c |", board[i][j]);
			}
			else
			{
				printf(" %c \n", board[i][j]);
			}
		}
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
				{
					printf("---|", board[i][j]);
				}
				else
				{
					printf("---\n", board[i][j]);
				}
			}
		}		
	}
}

void Playermove(char board[ROW][COL], int row, int col)//�������
{
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	while (1)
	{
		printf("���������꣺\n");
		scanf("%d%d", &x, &y);
		if (1 <= x && x <= row && 1 <= y && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã�");
			}
		}
		else
		{
			printf("���Ϸ������������룺");
		}
	}
}

void Computermove(char board[ROW][COL], int row, int col)//��������
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int Isfull(char board[ROW][COL], int row, int col)//�ж������Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)//�ж���Ӯ
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][1];
		}
	}
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[1][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == Isfull(board, ROW, COL))
	{
		return 'q';
	}
	return 'c';
}
