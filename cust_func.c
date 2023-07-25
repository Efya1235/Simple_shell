#include "shell.h"

/**
  * _atoi - Convert a string to an integer
  * @h: The pointer to convert
  * Return: An integer
  */
int _atoi(char *h)
{
	int q = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (h[q])
	{
		if (h[q] == 45)
		{
			min *= -1;
		}
		while (h[q] >= 48 && h[q] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (h[q] - '0');
			q++;
		}
		if (isi == 1)
		{
			break;
		}
		q++;
	}
	ni *= min;
	return (ni);
}

/**
  * _strlen - Returns the length of a string
  * @p: The string to get the length of
  * Return: The length of @p
  */
int _strlen(char *p)
{
	int length = 0;

	while (*p++)
		length++;
	return (length);
}

/**
  * _strcpy - Copy a string
  * @dest: Destination value
  * @src: Source value
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, char *src)
{
	int u;

	for (u = 0; src[u] != '\0'; u++)
	{
		dest[u] = src[u];
	}
	dest[u++] = '\0';
	return (dest);
}

/**
  * _strncpy - Copy a string
  * @dest: The buffer storing the string copy
  * @src: The source string
  * @t: The maximum number of bytes to copy
  * Return: A pointer to the resulting string destination
  */
char *_strncpy(char *dest, char *src, int t)
{
	int index = 0, src_len = 0;

	while (src[index++])
		src_len++;
	for (index = 0; src[index] && index < t; index++)
		dest[index] = src[index];
	for (index = src_len; index < t; index++)
		dest[index] = '\0';
	return (dest);
}

/**
  * _strncat - Concatenate two strings using at most
  * an inputted number of bytes from src
  * @dest: The string to be appended
  * @src: The string to be appended to dest
  * @g: The number of bytes from src to be appended to dest
  * Return: A pointer to the resulting string destination
  */
char *_strncat(char *dest, char *src, int g)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index] && index < g; index++)
		dest[dest_len++] = src[index];
	return (dest);
}
