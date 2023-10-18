#include "shell.h"
/**
 * pathfinder - a Nissan 4x4 truck, joking it looks for the path
 * @input: the command to be looked for
 * Return: full path
 */
char *pathfinder(char *input)
{
	char *path_env = _getenv("PATH");
	char *path_copy = _strdup(path_env);
	char *path_dir = NULL, *full = NULL;
	char *full_path = malloc(_strlen(input) + 20);

	if (access(input, F_OK) == 0)
	{
		free(path_copy);
		free(full_path);
		return (_strdup(input));
	}
	if (full_path == NULL)
	{
		perror("malloc fullpath error");
		exit(124);
	}
	if (path_copy == NULL)
	{	perror("strdup error");
		exit(124); }

	path_dir = strtok(path_copy, ":");
	while (path_dir)
	{	full_path[0] = '\0';
		_strcpy(full_path, path_dir);
		_strcat(full_path, "/");
		_strcat(full_path, input);

		if (access(full_path, F_OK) == 0)
		{	full = _strdup(full_path);
			free(path_copy);
			free(full_path);
			return (full); }

		path_dir = strtok(NULL, ":"); }
	free(full);
	free(full_path);
	free(path_copy);
	return (NULL);
}

/**
 * main - main program
 * Return: 1 0
 */
int main(void)
{
	char *tknptr, *argv[7], *full_path = NULL, *input = NULL;
	size_t n = 0;
	ssize_t gtln;
	int i = 0;

	while (1)
	{
		isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "$ ", 2) : 0;
		gtln = getline(&input, &n, stdin);
		if (gtln == -1 || _strcmp(input, "exit\n") == 0)
		{ argv[0] = NULL;
			break; }
		if (_strcmp(input, "env\n") == 0)
		{ print_env();
			continue; }
		gtln > 0 ? input[gtln - 1] = '\0' : 0;
		for (i = 0; (tknptr = strtok(i == 0 ? input : NULL, " ")); i++)
		{ argv[i] = tknptr; }
		argv[i] = NULL;
		if (argv[0] == NULL || _strcmp(argv[0], "\t") == 0)
		{continue; }
		full_path = pathfinder(argv[0]);
		if (full_path != NULL)
		{argv[0] = _strdup(full_path); }
		else
		{ perror(argv[0]);
			continue; }
		free(full_path);
		forky(argv, environ);
		free(argv[0]); }
	free(input);
	return (0); }
/**
 * execute - executes the argv from main
 * @exe: the executable command
 * @envv: the environ from the child
 */
void execute(char **exe, char **envv)
{
	if (execve(exe[0], exe, envv) == -1)
	{
		exit(127);
	}

}
/**
 * forky - makes children
 * @arg: parent
 * @ennv: idk leave me alone
 */
void forky(char **arg, char **ennv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
		if (child == 0)
		{
			execute(arg, ennv);
			exit(0);
		}
		else
		{
			waitpid(child, &status, WUNTRACED);
		}
}
