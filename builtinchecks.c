#include "shell.h"
/**
 * buildcheck - function
 * Description: checks whether commands are buidin
 * @av: arguments array
 * Return: pointer to prompt
 */
void(*buildcheck(char **av))(char **av)
{
	int k, n;
	buildin M[] = {
		{"env", env},
		{"exit", exittin},
		{"unsetenv", _unsetenv},
		{"setenv", _setenv},
		{NULL, NULL}
	};

	for (k = 0; M[k].com; k++)
	{
		n = 0;
		if (M[k].com[n] == av[0][n])
		{
			for (n = 0; av[0][n]; n++)
			{
				if (M[k].com[n] != av[0][n])
					break;
			}
			if (!av[0][n])
				return (M[k].func);
		}
	}
	return (0);

}

