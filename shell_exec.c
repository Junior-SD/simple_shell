#include "shell.h"

/**
 * string_split - function
 * Description: splits strings into array of pointers
 * @dlim: delimiter
 * @srn: string
 * Return: pointers array
 */
char **string_split(char *srn, const char *dlim)
{
	char **ar;
	char *cpy, tok;
	int i, j;

	cpy = malloc(_strlen(srn) + 1);
	if (cpy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (srn[i])
	{
		cpy[i] = srn[i];
		i++;
	}
	cpy[i] = '\0';

	tok = strtok(cpy, dlim);
	ar = malloc((sizeof(char *) * 2));
	ar[0] = _strdup(tok);

	i = 1; 
	j = 3;
	while (tok != NULL)
	{
		tok = strtok(NULL, dlim);
		ar = _realloc(ar, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		ar[i] = _strdup(tok);
		i++;
		j++;
	}
	free(cpy);
	return (ar);
}
/**
 * exec - function
 * Description: executes commands
 * @av: arguments array
 * Return: void
 */
void exec(char **av)
{
	int cond, p;

	if (!av || !av[0])
	{
	return;
	}
	p = fork();
	if (p == -1)
	{
		perror(_getenv("_"));
	}

	if (p == 0)
	{
		execve(av[0], av, environ);
			perror(av[0]);
		exit(EXIT_FAILURE);
	}
	wait(&cond);
}
/**
 * _realloc - function
 * Description: reallocates memory
 * @prv_sze: previous pointer size
 * @pr: prev pointer
 * @new_sze: pointer new size
 * Return: new pointer size
 */
void *_realloc(void *pr, unsigned int new_sze, unsigned int prev_sze)
{
	char *prev;
	char *new;

	unsigned int k;

	if (pr == NULL)
		return (malloc(new_sze));

	if (new_sze == prev_sze)
		return (pr);

	if (new_sze == prev_sze)
		return (pr);

	if (new_sze == 0 && pr != NULL)
	{
		free(pr);
		return (NULL);
	}

	prev = pr;
	new = malloc(new_sze);
	if (new == NULL)
		return (NULL);

	if (new_sze > prev_sze)
	{
		for (k = 0; k < prev_sze; k++)
			new[k] = prev[k];
		free(pr);
		for (k = prev_sze; k < new_sze; k++)
			new[k] = '\0';
	}
	if (new_sze < prev_sze)
	{
		for (k = 0; k < prev_sze; k++)
			new[k] = prev[k];
		free(pr);
	}
	return (new);
}
/**
 * freeav - function
 * Description: frees array
 * @av: array of pointers
 * Return: void
 */
void freeav(char **av)
{
	int j;

	for (j = 0; av[j]; j++)
		free(av[j]);
	free(av);
}




	
