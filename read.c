#include "shell.h"
/**
  * read_ptr - Reads user input
  * Return: characters read
  */

char *read_ptr()
{
	char *inputptr = NULL;
	size_t y = 0;
	ssize_t user_input;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "Simple shell$ ", 14);
	}

	user_input = getline(&inputptr, &y, stdin);

	if (user_input == -1)
	{
		free(inputptr);
		return (NULL);
	}

	if (inputptr[0] == '\n' || (strspn(inputptr, "  \t\n\r") == strlen(inputptr)))
	{
		free(inputptr);
		return (read_ptr());
	}

	return (inputptr);
}
