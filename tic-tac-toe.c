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
	printf("请玩家输入横纵坐标：");
	while (1)
	{
		scanf("%d%d", &row, &col);
		{
			if (row<0||row>MAX_ROW||col<0||col>MAX_COL)
			{
				printf("输入有误，请重新输入：");
				continue;
			}
		}
		if (ChessBoard[row][col] != ' ')
		{
			printf("此处已经有子，请重新输入：");
			continue;
		}
		ChessBoard[row][col] = '*';
		break;
	}
}

char isfull(char ChessBoard[MAX_ROW][MAX_COL])//返回1，满了		返回0，未满
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

char iswin(char ChessBoard[MAX_ROW][MAX_COL])//返回*，玩家胜	返回o，电脑胜	返回 ，继续		返回f ，平局
{
	//胜利
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
	//和棋
	if (isfull(ChessBoard) == 1)
	{
		return 'f';
	}
	//继续
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
	//1、定义数组，初始化棋盘
	init(ChessBoard);
	while (1)
	{
		//2、打印
		system("cls");
		printchess(ChessBoard);
		//3、玩家落子
		playermove(ChessBoard);
		//4、判定
		ret = iswin(ChessBoard);
		if (ret != ' ')
		{
			break;
		}
		//5、电脑落子
		commove(ChessBoard);
		//6、判定
		if (ret != ' ')
		{
			break;
		}
	}
	//7、打印棋盘
	printchess(ChessBoard);
	if (ret == '*')
	{
		printf("玩家获胜！！！\n");
	}
	if (ret == 'o')
	{
		printf("电脑胜利~~~\n");
	}
	if (ret == 'f')
	{
		printf("平局。。。\n");
	}
	
	system("pause");
	return 0;
}