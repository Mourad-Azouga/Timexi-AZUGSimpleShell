#include "shell.h"
/**
 * main - main program
 */
void execute(char **exe);

int main(void)
{
char *input = NULL, *tknptr, *argv[5];
size_t n = 0;
ssize_t gtln;
int i = 0, status = 0, j = 0;
pid_t child;
while (1)
{
if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		gtln = getline(&input, &n, stdin);
			if (gtln == -1)
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		if (gtln > 0 && input[gtln - 1] == '\n')
			{
				input[gtln - 1] = '\0';
			}
		tknptr = strtok(input, " ");
		while (tknptr != NULL)
			{
				argv[i] = tknptr;
				tknptr = strtok(NULL, " ");
				i++;
			}
		argv[i] = NULL;
		if (i > 0)
		{
		child = fork();
		if (child == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
			if (child == 0)
			{
			execute(argv);
			exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(child, &status, 0);
			}
		}
		for (j = 0; j <= i; j++)
		{
			argv[j] = NULL;
		}
		i = 0;

	}
else
	{
	}
}
return (0);
}
/**
 * execute - executes the argv from main
 */
void execute(char **exe)
{
	if (execve(exe[0], exe, environ) == -1)
	{
		perror(exe[0]);
		exit(EXIT_FAILURE);
	}
}
