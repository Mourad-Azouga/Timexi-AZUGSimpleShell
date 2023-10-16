#include "shell.h"
/*this file contains all print stuff*/
/**
 * print_env - prints env after the condition
 */
void print_env(void)
{
            char **env = environ;

    while (*env != NULL) {
        puts(*env);
        env++;
    }
}
