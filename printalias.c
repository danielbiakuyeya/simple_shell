#include "shell.h"

/**
 * print_alias - function to print alais if it exist in the project
 * @alias: alias name in the project
 * Return: Always Nothing
 */

void print_alias(alias *alias)
{
	size_t i;

	for (i = 0; alias[i].alias_name != NULL; i++)
	{
		write(STDOUT_FILENO, alias[i].alias_name, _strlen(alias[i].alias_name));
		write(STDOUT_FILENO, "='", 3);
		write(STDOUT_FILENO, alias[i].alias_args, _strlen(alias[i].alias_args));
		write(STDOUT_FILENO, "'\n", 2);
	}
}
