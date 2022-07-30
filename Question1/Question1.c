#include <stdio.h>
#include <stdlib.h>

void generate(char* charSet, int charSetSize, char* phrase, int phraseLen)
{
	//halting condition
	if (phraseLen == 0)
	{
		printf("%s\n", phrase);
		return;
	}

	for (int i = 0; i < charSetSize; i++)
	{

	}
}

int main()
{
	const int MAX_PHRASE_LEN = 3;
	char* phrase = (char*)calloc(MAX_PHRASE_LEN + 1, sizeof(*phrase));
	if (phrase == NULL)
		exit(1);
	char charSet[] = { '1','2','3','4' };
	int charSetSize = sizeof(charSet) / sizeof(charSet[0]);

	for (int i = 1; i <= MAX_PHRASE_LEN; i++)
	{
		printf("all sequences of length %d:\n", i);
		printf("##########################\n");
		generate(charSet, charSetSize, phrase, i);
	}

	free(phrase);
	return 0;
}
