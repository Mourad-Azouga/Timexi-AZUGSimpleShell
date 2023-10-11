#include "shell.h"
char *input = NULL, *argv[5];
void sigint_handler(int signum)
{
	int i = 0;
	if (signum == SIGINT)
	{
		free(input);
		                for (i = 0; argv[i] != NULL; i++)
                {
                free(argv[i]);
                }
    exit(EXIT_SUCCESS);
}
}
/**
 * main - main program
 */
void execute(char **exe);
int main(void)
{
char *tknptr;
size_t n = 0;
ssize_t gtln;
int i = 0, status = 0, j = 0;
pid_t child;

signal(SIGINT, sigint_handler);
while (1)
{
if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
		gtln = getline(&input, &n, stdin);
			if (gtln == -1)
			{
				break;
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
free(input);
return (0);
}
/**
 * execute - executes the argv from main
 */
void execute(char **exe)
{
	int i = 0;
	if (execve(exe[0], exe, environ) == -1)
	{
		perror(exe[0]);
		for (i = 0; exe[i] != NULL; i++)
		{
		free(exe[i]);
		}
		exit(EXIT_FAILURE);
	}
}

