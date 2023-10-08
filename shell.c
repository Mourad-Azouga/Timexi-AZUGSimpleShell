#include "shell.h"

int main(void)
{
size_t n = 1;
char *exe[2],*buff = NULL;
pid_t child;
int status;
ssize_t llen;

while (1)
{
printf("$ ");
llen = getline(&buff, &n, stdin);
if (llen == -1)
{
	perror("getline error");
}

if (llen > 0 && buff[llen - 1] == '\n')
buff[llen - 1] = '\0';
exe[0] = strdup(buff);
        if (exe[0] == NULL)
        {
            perror("strdup error");
            free(buff);
            continue;
        }
exe[1] = NULL;
{
	child = fork();
	if (child == -1)
	{
	perror("error");
	return (-1);
	}
	else
	if (child == 0)
	{

			if (execve(exe[0], exe, NULL) == -1)
		{
				perror("Error");
		}
	}
	else
        {
			waitpid(child, &status, 0);
			free(exe[0]);
			free(buff);
	}

}
}
return (0);
}
