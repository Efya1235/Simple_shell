#include "shell.h"

/**
 *handle_shell - prints prompt, takes input and also executes
 */
void handle_shell(void)
{
	char *inputptr = NULL;
	char *args[Max_Arguments];
	int argCount;

	/* **environ_ptr;
	   int o;
	   extern char **environ;*/

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

		/*print_tokens(args);*/

		/*if (strcmp(args[0], "exit") == 0)
		  {
		  for (o = 0; args[o] != NULL; o++)
		  {
		  free(args[o]);
		  }
		  free(inputptr);
		  handle_shell_exit(args[1]);
		  }
		  else if (strcmp(args[0], "env") == 0)
		  {
		  environ_ptr = environ;
		  while (*environ_ptr != NULL)
		  {
		  write(STDOUT_FILENO, *environ_ptr, strlen(*environ_ptr));
		  write(STDOUT_FILENO, "\n", 1);
		  environ_ptr++;
		  }
		  }
		  else
		  {
		  handle_command_execution(args);
		  }
		  */
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

	for (b = 0; b < arg_count; b++) {
		free(args[b]);
	}
}
