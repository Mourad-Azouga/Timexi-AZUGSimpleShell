#include "shell.h"
char *pathfinder(char *input)
{
        char *path_env = getenv("PATH");
        char *path_dir = NULL;
        char *full_path = NULL;
        path_dir = strtok(path_env, ":");
        while (path_dir)
        {
                full_path = malloc(strlen(path_dir) + strlen(input) + 2);
                if (full_path == NULL)
                {
                        perror("malloc fullpath error");
                        exit(EXIT_FAILURE);
                }
                full_path[0] = '\0';
                strncat(full_path, path_dir, strlen(path_dir));
                strcat(full_path, "/");
                strncat(full_path, input, strlen(input));
                if (access(full_path, X_OK) == 0)
                {
                        return (full_path);
                }
                free(full_path);
                path_dir = strtok(NULL, ":");
        }
        return (NULL);
}
