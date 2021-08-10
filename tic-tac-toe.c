#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROW 3
#define MAX_COL 3

void init(char ChessBoard[MAX_ROW][MAX_COL])
{
	srand((unsigned int)time(0));
	for (int row=0;row<MAX_ROW;row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			ChessBoard[row][col] = ' ';
		}
	}
}

void printchess(char ChessBoard[MAX_ROW][MAX_COL])
{
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++)
	{
		printf("|");
		for (int col = 0; col < MAX_COL; col++)
		{
			printf(" %c |", ChessBoard[row][col]);
		}
		printf("\n+---+---+---+\n");
	}
}

void playermove(char ChessBoard[MAX_ROW][MAX_COL])
{
	int row = 0;
	int col = 0;
	printf("���������������꣺");
	while (1)
	{
		scanf("%d%d", &row, &col);
		{
			if (row<0||row>MAX_ROW||col<0||col>MAX_COL)
			{
				printf("�����������������룺");
				continue;
			}
		}
		if (ChessBoard[row][col] != ' ')
		{
			printf("�˴��Ѿ����ӣ����������룺");
			continue;
		}
		ChessBoard[row][col] = '*';
		break;
	}
}

char isfull(char ChessBoard[MAX_ROW][MAX_COL])//����1������		����0��δ��
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (ChessBoard[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char iswin(char ChessBoard[MAX_ROW][MAX_COL])//����*�����ʤ	����o������ʤ	���� ������		����f ��ƽ��
{
	//ʤ��
	for (int row = 0; row < MAX_ROW; row++)
	{
		if (ChessBoard[row][0] != ' ' && ChessBoard[row][0] == ChessBoard[row][1] && ChessBoard[row][0] == ChessBoard[row][2])
		{
			return ChessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++)
	{
		if (ChessBoard[0][col] != ' ' && ChessBoard[0][col] == ChessBoard[1][col] && ChessBoard[0][col] == ChessBoard[2][col])
		{
			return ChessBoard[0][col];
		}
	}
	if (ChessBoard[0][0] != ' ' && ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2])
	{
		return ChessBoard[1][1];
	}
	if (ChessBoard[0][2] != ' ' && ChessBoard[0][2] == ChessBoard[1][1] && ChessBoard[0][2] == ChessBoard[2][0])
	{
		return ChessBoard[1][1];
	}
	//����
	if (isfull(ChessBoard) == 1)
	{
		return 'f';
	}
	//����
	return ' ';
}

void commove(char ChessBoard[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (ChessBoard[row][col] != ' ')
		{
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}
}

int main()
{
	char ChessBoard[MAX_ROW][MAX_COL];
	char ret = ' ';
	//1���������飬��ʼ������
	init(ChessBoard);
	while (1)
	{
		//2����ӡ
		system("cls");
		printchess(ChessBoard);
		//3���������
		playermove(ChessBoard);
		//4���ж�
		ret = iswin(ChessBoard);
		if (ret != ' ')
		{
			break;
		}
		//5����������
		commove(ChessBoard);
		//6���ж�
		if (ret != ' ')
		{
			break;
		}
	}
	//7����ӡ����
	printchess(ChessBoard);
	if (ret == '*')
	{
		printf("��һ�ʤ������\n");
	}
	if (ret == 'o')
	{
		printf("����ʤ��~~~\n");
	}
	if (ret == 'f')
	{
		printf("ƽ�֡�����\n");
	}
	
	system("pause");
	return 0;
}