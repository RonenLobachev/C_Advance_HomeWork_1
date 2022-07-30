#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

//Defines
#define TRUE 1
#define FASLE 0

#define MAX_ARRAY_COL_ROW 10

//Types
typedef unsigned char bool;


//Local Declarations
bool GetArrayFromUser(unsigned char* inout_pu8Array, int* out_i32N)
{
	bool bRet = TRUE;
	int i32Tmp = 0;
	unsigned char u8Tmp = 0;
	do {
		printf("Enter size of square array:\n");
		i32Tmp = sscanf("%d", out_i32N);
	} while ((*out_i32N < 0) || (*out_i32N > MAX_ARRAY_COL_ROW));
	
	for (int i = 0; i < *out_i32N; i++)
	{
		for (int j = 0; j < *out_i32N; j++)
		{
			do {
				printf("Set 0 or 1 to array cell [%d][%d]\n",i,j);
				i32Tmp = sscanf("%u", &u8Tmp);
			} while (u8Tmp > 1);
		}
	}
	
}

void main()
{
	int i32row = 0, i32col = 0;
	unsigned char* pu8Array = NULL;


}