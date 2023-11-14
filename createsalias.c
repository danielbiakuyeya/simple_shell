#include "shell.h"

/**
 * add_node - to create a new alias node in the project
 * @head: head of the node in the project
 * @name: alias name in the project
 * @args: alias argument in the project
 * Return: Null on failure, or return head of new node
 */

a_node *add_node(a_node **head, char *name, char *args)
{
	a_node *new_node;
	int name_len = 0;
	int arg_len = 0;

	new_node = malloc(sizeof(a_node));

	if (new_node == NULL)
		return (NULL);
	while (name[name_len])
		name_len++;
	while (args[name_len])
		arg_len++;
	new_node->alias_name = _strdup(name);
	new_node->alias_args = _strdup(args);
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
