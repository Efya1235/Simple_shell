#include "shell.h"



void print_tokens(char **args) 
{
	int i;
	printf("Tokens:\n");
	for (i = 0; args[i] != NULL; i++) 
	{
        printf("args[%d]: %s\n", i, args[i]);
	}
}
