#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <stddef.h>

char *_strdup(char *str);
int _putchar(char c);
void _puts(char *srn);
int _strlen(char *srn);
void sig_man(int sig_prom);
void file_EOF(int glen, char *buf);
void t_satty(void);
list_path *end_node(list_path **pd, char *ptr);

extern char **environ;



typedef struc list_path
{
	char *pin;
	struct list_path *l;
} list_path;
	










