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
#define TRUE 1
#define FALSE 0

/*SHELL.C*/
void execute(char **exe);
char *pathfinder(char *input);

/*STRING.c*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);

/*PRINT.C*/
void print_env(void);
int _putchar(int c);
void _puts(char *str);
#endif /*SHELL_H*/
