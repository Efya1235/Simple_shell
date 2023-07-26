#include "shell.h"

/**
 * custom_getline - function that works as the standard deadline function
 * @lineptr: pointer to the array
 * @n: hold the size of the memory
 * @stream: location or file read from
 * Return: number of character read
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = *n;
	ssize_t bytes_read;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	*lineptr = (char *)malloc(buffer_size * sizeof(char));
	if (*lineptr == NULL)
	{
		return (-1);
	}
	bytes_read = getline(lineptr, &buffer_size, stream);
	if (bytes_read == -1)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}
	*n = buffer_size;
	return (bytes_read);
}
