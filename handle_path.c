#include "shell.h"

/**
*handle_command_path - finds path of command imputed for execution
*@args: array of string or characters that make up the command
*Return: path of the command if it exists
*/

char *handle_command_path(char *args)
{
	char *path, *token, *path_copy, command[Max_Arguments], *temp;

	if (args[0] != '/')
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			perror("Allocation Failed");
		}
		if (path != NULL)
		{
			path_copy = strdup(path);
			if (path_copy == NULL)
			{
				perror("Allocation failed");
				return (NULL);
			}
			token = strtok(path_copy, ":");
			while (token != NULL)
			{
				snprintf(command, sizeof(command), "%s/%s", token, args);
					if (access(command, X_OK) == 0)
					{
						temp = strdup(command);
						free(path_copy);
						return (temp);
					}
				token = strtok(NULL, ":");
			}
			free(path_copy);
		}
	}
	return (args);
}
