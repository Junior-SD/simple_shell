#include "shell.h"
/**
 * end_node - function
 * Decsription: adds node to end of list
 * @ptr: pointer to string
 * @pd: pointer to pointer of the linked list
 * Return: address to new node
 */
list_path *end_node(list_path **pd, char *ptr)
{
	list_path *add;
	list_path *tp;

	add = malloc(sizeof(list_path));

	if (!add || !ptr)
	{
		return (NULL);
	}

	add->pin = ptr;

	add->l = '\0';
	if (!*pd)
	{
		*pd = add;
	}
	else
	{
		tp = pd;

		while (tp->l)
		{
			tp = tp->l;
		}

		tp->l = add;
	}

	return (*pd);
}
/**
 * _getenv - function
 * Description: acquires global variable value
 * @ent: variable
 * Return: vaue of string
 */
char *_getenv(const char *ent)
{
	char *val;
	int k, l;

	if (ent == NULL)
	{
		return (NULL);
	}

	for (k = 0; environ[k]; k++)
	{
		l = 0;
		if (ent[l] == environ[i][j])
		{
		while (ent[l])
		{
		if (ent[l] != environ[k][l])
			break;
		l++;
		}
		if (ent[l] == '\0')
		{
		val = (environ[k] + l + 1)
		return (val);
		}
	}
	return (0);

}
/**
 * linkpname - function
 * Description: provides linked list for path directions
 * @pname: path value string
 * Return: pointer to the linked list created
 */
list_path *linkpname(char *pname)
{
	char *tok;
	list_path *phead = NULL;
	char *spname= _strdup(pname);

	tok = strtok(spname, ":");
	while (tok)
	{
		phead = end_node(&phead, tok);
		tok = strtok(NULL, ":");
	}

	return (phead);
}
/**
 * _twhich - function
 * Description: establishes the pname of a file
 * @node: front node of linked lists
 * @fname: name of command or file
 * Return: NULL if no match, otherwise pname of file
 */
char *_twhich(char *fname, list_path *node)
{
	struct stat fd;
	char *srn;

	list_path *tp = node;

	while (tp)
	{
		srn = concat_all(tp->pin, "/", fname);
		if (stat(srn, &fd) == 0)
		{
			return (srn);
		}

		free(srn);
		tp = tp->l;
	}

	return (NULL);
}
/**
 * free_ls - function
 * Description: frees lists
 * @node: pointer to the linked list
 */
void free_ls(list_path *node)
{
	list_path *byt;

	while (node != NULL)
	{
		byt = node->l;
		free(node->pin);
		free(node);
		node = byt;
	}
}

