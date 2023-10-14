#include "shell.h"

char *input = NULL;

/**
 * pathfinder - a Nissan 4x4 truck, joking it looks for the path
 * @input: the command to be looked for
 * Return: full path
 */
char *pathfinder(char *input)
{
    char *path_env = getenv("PATH");
    char *path_copy = strdup(path_env);
    char *path_dir = NULL;
    char *full_path = NULL, *full_path_copy = NULL;

    if (path_copy == NULL)
    {
        perror("strdup error");
        exit(EXIT_FAILURE);
    }

    path_dir = strtok(path_copy, ":");
    while (path_dir)
    {
        full_path = malloc(strlen(path_dir) + strlen(input) + 2);
        if (full_path == NULL)
        {
            perror("malloc fullpath error");
            exit(EXIT_FAILURE);
        }

        full_path[0] = '\0';
        strcpy(full_path, path_dir);
        strcat(full_path, "/");
        strcat(full_path, input);

        if (access(full_path, F_OK) == 0)
        {
            free(path_copy);
            full_path_copy = full_path;
            full_path = NULL;
            return (full_path_copy);
        }

        free(full_path);
        full_path = NULL;
        path_dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
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
			exit(0);
			}
			else
			{
				waitpid(child, &status, WUNTRACED);
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
return (EXIT_SUCCESS);
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

