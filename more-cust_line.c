#include "shell.h"

/**
 * _strcmp - comparing two strings
 * @m1: A pointer to the first string to be compared
 * @m2: A pointer to the second string to be compared
 * Return: if str1 == str2, 0;
 * if str1 > str2, the positive difference of the unmatched characters
 * if str1 < str2, the negative difference of the firt unmatched char
 */
int _strcmp(char *m1, char *m2)
{
	while (*m1 && *m2 && *m1 == *m2)
	{
		m1++;
		m2++;
	}
	return (*m1 - *m2);
}

/**
 * _strcat - concatenating two strings
 * @dest: the destination string
 * @src: the source string
 * Return: A pointer to the resulting string destination
 */
char *_strcat(char *dest, char *src)
{
	size_t destlen = strlen(dest);
	size_t srclen = strlen(src);
	char *result = (char *)malloc((destlen + srclen + 1) * sizeof(char));

	if (result == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}
	strcpy(result, dest);
	strcat(result, src);
	return (result);
}

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to pe copied
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *result = (char *)malloc(n * sizeof(char));

	if (result == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}
	for (unsigned int i = 0; n > 1; i++)
	{
		result[i] = src[i];
	}

	memcpy(dest, result, n);
	free(result);
	return (dest);
}

/**
 * _isdigit - checker for digit characters
 * @j: the character to be checked
 * Return: 1 for a digit character, 0 otherwise
 */
int _isdigit(int j)
{
	return (j >= '0' && j <= '9');
}
