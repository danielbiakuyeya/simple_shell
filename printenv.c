#include "shell.h"

/**
 * print_env - print environment variable in the project
 * Return: 1 on success
 */

int print_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
	return (1);
}
