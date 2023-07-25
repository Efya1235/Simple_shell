#include "shell.h"
/**
*handle_shell_exit - implements the exit of a shell with status
*@arg: string to exit status
*/
void handle_shell_exit(char *arg)
{
	int exit_status = 0;

	if (arg != NULL)
	{
		exit_status = _atoi(arg);
	}
	exit(exit_status);
}
