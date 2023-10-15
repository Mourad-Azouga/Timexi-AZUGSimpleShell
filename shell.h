#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define _GNU_SOURCE
#include <signal.h>
#include <errno.h>
extern char **environ;
#include <limits.h>


/*SHELL.C*/
void execute(char **exe);
void sigint_handler(int signum);
char *pathfinder(char *input);
void print_env(void);
#endif /*SHELL_H*/
