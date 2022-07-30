#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

//Defines
#define TRUE 1
#define FALSE 0

#define N 4

//Types
typedef unsigned char bool;


//Local Declarations
void PrintArray(const unsigned char in_pu8Array[][N]);
int path_exists(unsigned char mat[][N], int rows, int cols);

/*****************MAIN*****************************/
void main()
{
	int i32row = 0, i32col = 0;
	int i32Tmp;
	unsigned char au8Array[N][N];
	unsigned char u8Tmp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			do {
				printf("Set 0 or 1 to array cell [%d][%d]\n", i, j);
				i32Tmp = scanf("%hhu", &u8Tmp);
			} while (u8Tmp > 1);
			au8Array[i][j]= u8Tmp;
		}
	}

	PrintArray(au8Array);
	if (path_exists(au8Array, 0, 0))
	{
		printf("Found path\n");
	}
	else
	{
		printf("Not found path\n");
	}
	exit(0);
}

//Service functions
void PrintArray(const unsigned char in_pu8Array[][N])
{
	if (in_pu8Array == NULL)
	{
		printf("Passed array empty of have not correct lenght\n");
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		printf("| ");
		for (int j = 0; j < N; j++)
		{
			printf("%d | ", in_pu8Array[i][j]);
		}
		printf("\n");
	}
}

int path_exists(unsigned char mat[][N], int rows, int cols)
{
	int i32Ret = -1;
	//Case when we "arived" to cell [N-1][N-1] with value 1
	if ((rows == N - 1) && (cols == N - 1) && (mat[rows][cols] == 1))
	{
		return 1;
	}
	
	//check rigth cell
	if (((cols + 1) < N) && (mat[rows][cols + 1] == 1))
	{
		i32Ret = path_exists(&(*mat), rows, cols+1);
	}
	//check down cell
	if (((rows + 1) < N) && (mat[rows + 1][cols] == 1))
	{
		i32Ret = path_exists(&(*mat), rows+1, cols);
	}
	//check right diagonal
	if (((rows + 1) < N) && ((cols + 1) < N) && (mat[rows + 1][cols + 1] == 1))
	{
		i32Ret = path_exists(&(*mat), rows + 1, cols + 1);
	}
	return i32Ret;
}