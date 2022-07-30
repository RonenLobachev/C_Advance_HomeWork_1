#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

//Defines
#define TRUE 1
#define FALSE 0

#define MAX_ARRAY_COL_ROW 10

//Types
typedef unsigned char bool;


//Local Declarations
bool GetArrayFromUser(unsigned char** out_pu8Array, int* out_i32N);
void PrintArray(const unsigned char* in_pu8Array, int in_i32N);

/*****************MAIN*****************************/
void main()
{
	int i32row = 0, i32col = 0;
	unsigned char* pu8Array = NULL;
	int i32N = 0;

	if (!GetArrayFromUser(&pu8Array, &i32N))
	{
		printf("Bad allocation. Programm terminated\n");
		exit(1);
	}

	PrintArray(pu8Array, i32N);
	free(pu8Array);
	exit(0);
}

//Service functions
bool GetArrayFromUser(unsigned char** out_pu8Array, int* out_i32N)
{
	bool bRet = TRUE;
	int i32Tmp = 0;
	unsigned char u8Tmp = 0;
	unsigned char* au8Tmp = NULL;
	do {
		printf("Enter size of square array:\n");
		i32Tmp = scanf("%d", out_i32N);
	} while ((*out_i32N < 0) || (*out_i32N > MAX_ARRAY_COL_ROW));

	*out_pu8Array = (unsigned char*)calloc((int)pow(*out_i32N, 2), (int)sizeof(*out_pu8Array));
	if (*out_pu8Array == NULL)
	{
		bRet = FALSE;
	}
	
	au8Tmp = *out_pu8Array;

	for (int i = 0; (i < *out_i32N) && (bRet != FALSE); i++)
	{
		for (int j = 0; j < *out_i32N; j++)
		{
			do {
				printf("Set 0 or 1 to array cell [%d][%d]\n", i, j);
				i32Tmp = scanf("%hhu", &u8Tmp);
			} while (u8Tmp > 1);
			au8Tmp[i * (*out_i32N) + j] = u8Tmp;
		}
	}

	return bRet;
}

void PrintArray(const unsigned char* in_pu8Array, int in_i32N)
{
	if ((in_pu8Array != NULL) && (in_i32N <= 0))
	{
		printf("Incoming array have size %dX%d\n", in_i32N, in_i32N);
	}
	else
	{
		printf("Passed array empty of have not correct lenght\n");
		return;
	}
	
	for (int i = 0; i < in_i32N; i++)
	{
		printf("| ");
		for (int j = 0; j < in_i32N; j++)
		{
			printf("%d | ", in_pu8Array[i * in_i32N + j]);
		}
		printf("\n");
	}
}