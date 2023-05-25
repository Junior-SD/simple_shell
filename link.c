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
		l = 
