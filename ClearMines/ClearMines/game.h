#pragma once
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set);//��ʼ������
void DisplayBoard(char Board[ROWS][COLS], int row, int col);//��ӡ����
void SetMine(char Board[ROWS][COLS], int row, int col);//������
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//ɨ��