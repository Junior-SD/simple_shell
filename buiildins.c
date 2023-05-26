#include "shell.h"
/**
 * exittin - function
 * Description: exits shell
 * @av: array entered
 */
void exittin(char **av)
{
	int m, p;

	if (av[1])
	{
		p = _atoi(av[1]);
		if (p <= -1)
			p = 2;
		freeav(av);
		exit(p);
	}
	for (m = 0; av[m]; m++)
		free(av[m]);
	free(av);
	exit(0);
}

/**
 * _atoi - function
 * Description: converts strings into integers
 * @st: string pointer
 * Return: integers
 */
int _atoi(char *st)
{
	int k, intg;
	int sgn = 1;

	k = 0;
	intg = 0;
	while (!((st[k] >= '0') && (st[k] <= '9')) && (st[k] != '\0'))
	{
		if (st[k] == '-')
		{
			sgn = sgn * (-1);
		}
		k++;
	}
	while ((st[k] >= '0') && (st[k] <= '9'))
	{
		intg = (intg * 10) + (sgn * (st[k] - '0'));
		k++;
	}
	return (intg);
}
/**
 * env - function
 * Description: prints current env
 * @_attribute_((unused) - arguments array
 */
void env(char **av _attribute_((unused)))
{
	int j;

	for (j = 0; environ[j]; j++)
	{
	_puts(environ[j]);
	_puts("\n");
	}
}
/**
 * _setenv - function
 * Description: initializes or modifies a variable for a new environment
 * @av: array entered
 */
void _setenv(char **av)
{
	int c, d, e;

	if (!av[1] || !av[2])
	{
	perror(_getenv("_"));
	return;
	}

	for (c = 0; environ[c]; c++)
	{
		d = 0;
		if (av[1][d] == environ[c][d])
		{
			while (av[1][d])
			{
			if (av[1][d] != environ[c][d])
				break;
			d++;
			}
			if (av[1][d] == '\0')
			{
				e = 0;
				while (av[2][e])
				{
					environ[c][d + 1 + e] = av[2][e];
					e++;
				}
				environ[c][d + 1 + e] = '\0';
				return;
			}
		}
	}
	if (!environ[c])
	{
		environ[c] = concat_all(av[1], "=", av[2]);
		environ[c + 1] = '\0';
	}
}
/**
 * _unsetenv - function
 * Description: removes the variable of an environment
 * @av: entered words array
 */
void _unsetenv(char **av)
{
	int m, n;

	if (!av[1])
	{
	perror(_getenv("_"));
	return;
	}
	for (m = 0; environ[m]; m++)
	{
		n = 0;
		if (av[1][n] == environ[m][n])
		{
			while (av[1][n])
			{
				if (av[1][n] != environ[m][n])
					break;
				n++;
			}
			if (av[1][n] == '\0')
			{
				free(environ[m]);
				environ[m] = environ[m + 1];
				while (environ[m])
				{
					environ[m] = environ[m + 1];
					m++;
				}
				return;
			}
		}
	}

}

