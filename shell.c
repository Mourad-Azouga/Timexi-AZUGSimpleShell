#include "shell.h"
char *input = NULL;
/**
 * sigint_handler - hanldes signal inputs
 * @signum: signal number
 */
void sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
}

/**
 * main - main program
 * Return: 1 0
 */
int main(void)
{
char *tknptr, *argv[5], *full_path = NULL;
size_t n = 0;
ssize_t gtln;
int i = 0, status = 0, j = 0, k = 0;
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
		full_path = pathfinder(argv[0]);
		if (full_path != NULL)
		{
			argv[0] = NULL;
			argv[0] = strdup(full_path);
			full_path = NULL;
			free(full_path);
		}
		if (access(argv[0], X_OK) == 0)
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
				waitpid(child, &status, WUNTRACED);
			}
		}
		else
			{
				perror(full_path);
			}
		for (j = 0; argv[j] != NULL; j++)
		{
			argv[j] = NULL;
		}
		i = 0;

	}
free(input);
for (k = 0; argv[k] != NULL; i++)
	{
	free(argv[k]);
	}
return (0);
}
/**
 * execute - executes the argv from main
 * @exe: the executable command
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

