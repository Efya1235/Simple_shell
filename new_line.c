#include "shell.h"

/**
*remove_trailing_newline - removes the trainling new line in a string
*@inputptr: pointer to the array of strings
*/
void remove_trailing_newline(char *inputptr)
{
	size_t length;

	length = strlen(inputptr);
	inputptr[length - (inputptr[length - 1] == '\n')] = '\0';
}
