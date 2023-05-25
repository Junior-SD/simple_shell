#include "shell.c"
/**
 * _strdup - returns a pointer to newly allocated space
 * Description: returns a pointer to a new string
 * @str: string
 *
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	char *m;
	int k = 1;
	int n = 0;

	if (str == NULL)
	{
	return (NULL);
	}

	while (str[k])
	{
	k++;
	}

	m = malloc((sizeof(char) * k) + 1);
	if (m == NULL)
	{
	return (NULL);
	}
	while (n < k)
	{
	m[n] = str[n];
	n++;
	}
	m[n] = '\0';

	return (m);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));

}
/**
 * _puts - function definition
 * Description: prints a string
 * @srn: string
 * Return: void
 */
void _puts(char *srn)
{
	for (; *srn != '\0'; srn++)
	{
	_putchar(*srn);
	}
	_putchar('\n');
}
/**
 * _strlen - function definition
 * Description: returns length of string
 * @srn: string
 * Return: string length
 */

int _strlen(char *srn)
{
	int l = 0;

	while (*srn++)
	l++;
	return (l);
}

