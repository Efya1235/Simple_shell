#include "shell.h"

/**
 * tokenize_arguments - tokenize argument passed to prompt by the user
 * @inputptr: pointer to the input string
 * @args: array of arguments
 */
int tokenize_arguments(char *inputptr, char **args)
{
	int argCount = 0;
	const char delimiter[] = " ";
	char *token;

	token = strtok(inputptr, delimiter);

	while (token != NULL && argCount < Max_Arguments - 1)
	{
		size_t tokenLength = strlen(token);

		args[argCount] = (char *)malloc((tokenLength + 1) * sizeof(char));

		if (args[argCount] == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		strcpy(args[argCount], token);
		argCount++;
		token = strtok(NULL, delimiter);
	}
	args[argCount] = NULL;

	return (argCount);
}
