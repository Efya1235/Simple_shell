#include "shell.h"

/**
 * handle_command_execution - executes a command that has been passed
 * @args: array of strings representing the command
 */
void handle_command_execution(char **args)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/*execute command in child process*/
		execvp(args[0], args);
		/*Execution reaches this point only if exe vp fails*/
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*Parent process waits for the child process to finish*/
		int status;

		waitpid(child_pid, &status, 0);
	}
}
