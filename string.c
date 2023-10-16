#include "shell.h"
/**
 * _strlen - calculates the length of sdtring
 * @s: string to be calculated
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;
	if (!s)
	return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}
/**
 * _strcpy - Copies a source string into the dest
 * @src: source
 * @dest: destination
 * Return: ptr to dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}
/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * Return: s1-s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}
char *_strdup(char *s)
{
size_t len = _strlen(s);
char *dupped = (char *)malloc(len + 1);
        if (s == NULL)
	{
		free(dupped);
		return (NULL); 
	}
if (dupped == NULL)
	{
	perror("strdup malloc error");
	exit(EXIT_FAILURE);
	}
	_strcpy(dupped, s);
	return (dupped);
}
