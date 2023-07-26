#include "shell.h"

/**
 *handle_shell - prints prompt, takes input and also executes
 */
void handle_shell(void)
{
	char *inputptr = NULL;
	char *args[Max_Arguments];
	int argCount;

	while (1)
	{
		inputptr = read_ptr();
		if (inputptr == NULL)
		{
			break;
		}

		remove_trailing_newline(inputptr);
		argCount = tokenize_arguments(inputptr, args);

		handle_command_execution(args);
		free(inputptr);
		free_args(args, argCount);
	}
}

/**
 * free_args - Used to free memory allocated by args
 * @args: command line arguments
 * @arg_count: number of arguments
 */
	void free_args(char **args, int arg_count)
	{
		int b;

		for (b = 0; b < arg_count; b++)
		{
			free(args[b]);
		}
	}
