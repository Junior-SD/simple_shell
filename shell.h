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
char *_getenv(const char *ent);
list_path *linkpname(char *pname);
char *_twhich(char *fname, list_path *node);
void free_ls(list_path *node);
char **string_split(char *srn, const char *dlim);
void exec(char **av);
void *_realloc(void *pr, unsigned int new_sze, unsigned int prev_sze);
void freeav(char **av);
void(*buildcheck(char **av))(char **av);
void exittin(char **av);
int _atoi(char *st);
void env(char **av_attribute_((unused)));
void _setenv(char **av);
void _unsetenv(char **av);

extern char **environ;

/**
 * struct list_path - path directories linked list
 * @pin: path of the directory
 * @l: next node pointer
 */

typedef struct list_path
{
	char *pin;
	struct list_path *l;
} list_path;
	
/**
 * 
 *
 */
typedef struct buildin
{
	char *com;
	void (*func)(char **);
} buildin;










