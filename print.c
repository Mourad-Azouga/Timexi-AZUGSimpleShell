#include "shell.h"
/*this file contains all print stuff*/
/**
 * print_env - prints env after the condition
 */
void print_env(void)
{
char **env = environ;

while (*env != NULL)
	{
	_puts(*env);
	env++;
	}
}
/**
 * _putchar - prints a character
 * @c: Character to be printed
 * Return: number of character written
 */

int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string followed by a newline
 * @str: string to be pritned
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
