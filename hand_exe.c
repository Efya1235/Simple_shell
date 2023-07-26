#include "shell.h"

/**
 * handle_command_execution - executes a command that has been passed
 * @args: array of strings representing the command
 */
void handle_command_execution(char **args)
{
	pid_t child_pid = fork();
	char *command;
	int arg_count;

	if (args[0] == NULL)
	{
		return;
	}

	else if  (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			arg_count = 0;
			free_args(args, arg_count);
			exit(0);
		}
			command = handle_command_path(args[0]);
			if (command == NULL)
			{
				perror("command not found");
			}
			if (execve(command, args, environ) == -1)
			{
				perror(command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/*Parent process waits for the child process to finish*/
			int status;

			waitpid(child_pid, &status, 0);
		}
	}
