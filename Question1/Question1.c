#include <stdio.h>
#include <stdlib.h>

#define OPTION_1

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
		//Trick - static variable create and initilized only on first call to function
		//So all other recursive call will have copy of this variable with last modifed value
		//In this case we can "fill" phrase array from start to end
		//Other option is "fill" phrase array is use next line - "phrase[phraseLen - 1] = charSet[i]"
		//Because on every recursive call will be passed phraseLen - 1 we fill phrase array from end to start
		//Its more compact but less readable
		#ifdef OPTION_1
				static unsigned int u32RecursionDepth = 0;
				phrase[u32RecursionDepth++] = charSet[i];
				generate(charSet, charSetSize, phrase, phraseLen - 1);
				u32RecursionDepth--;
		#else
				phrase[phraseLen - 1] = charSet[i];
				generate(charSet, charSetSize, phrase, phraseLen - 1);
		#endif
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
