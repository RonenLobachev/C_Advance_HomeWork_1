#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

int stringCompare(const char* str1, const char* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		printf("NULL pointer !\n");
		return -2;
	}

	if (*str1 != *str2)
	{
		//Case: str1 shorter then str2
		if (*str1 == '\0')
		{
			return -1;
		}
		//Case: str2 shorter then str1
		if (*str2 == '\0')
		{
			return 1;
		}
		if (*str1 < *str2)
		{
			return -1;
		}
		if (*str1 > *str2)
		{
			return 1;
		}
	}
	else
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		else
		{
			return stringCompare(str1 + 1, str2 + 1);
		}
	}
}

void HowBigger(int i32Val)
{
	switch (i32Val)
	{
	case -1:
		printf("First string smaller then second\n");
		break;
	case 1:
		printf("First string bigger then second\n");
		break;
	case 0:
		printf("Both strings equal\n");
		break;
	default:
		printf("Some major error ocured\n");
		break;
	}
}

void main()
{
	int i32Res = 0;
	char str1[30];
	char str2[30];

	while (1)
	{
		printf("Please insert first string. Max lenght is 30 chars\n");
		i32Res = scanf("%s", str1);
		printf("Please insert seconde string. Max lenght is 30 chars\n");
		i32Res = scanf("%s", str2);
		i32Res = stringCompare(str1, str2);
		HowBigger(i32Res);
		printf("\n\n");
	}
}