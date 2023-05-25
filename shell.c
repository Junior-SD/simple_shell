#include "shell.h"

/**
 * sig_man - function
 * Description: determines whether control + C works
 * @sig_prom: arg
 */
void sig_man(int sig_prom)
{
	if (sig_prom == SIGINT)
	{
		_puts("\njnshad$ ");
	}
}

/**
 * file_EOF - function
 * Description: handes EOF
 * @buf: buffer
 * @glen: getline func return
 */
void file_EOF(int glen, char *buf)
{
	(void)buf;

	/*check whether getline function is effective*/
	if (glen == -1)
	{
		/*proceed*/
		if (isatty(STDIN_FILENO)
		{
		_puts("\n");
		free(buf);
		}
		exit(98);
	}
}
/**
 * t_satty -function
 * Descriptin: verifies terminal
 * Return: void
 */
void t_satty(void)
{
	if (isatty(STDIN_FILENO))
	{
	_puts("jnshads$ ");
	}
}
/**
 * main - function
 * Description: create code
 * Return: 0
 */
int main(void)
{
	list_path head = '\0';
	size_t sze;
	ssize_t slen = 0;
	char *buf = NULL;
	char *pname, *val, **av;
	void (*fl)(char **);

	signal(SIGINT, sig_man);
	while (slen != EOF)
		t_satty();
		slen = getline(&buf, &sze, stdin);
		file_EOF(slen, buf);
		av = splitstring(buf, "\n");
		if (!av || !av[0])
			exec(av);
		else
			val = _getenv("PATH");
			head = linkpname(val);
			pname = _twhich(av[0], head);
			fl = buildcheck(av);
			if (fl)
				free(buf);
				fl(av);
			else if (!pname)
				exec(av);
			else if (pname)
				free(av[0]);
				av[0] = pname;
				exec(av);
	freeav(av);
	free_ls(head);
	free(buf)
	return (0);
}



