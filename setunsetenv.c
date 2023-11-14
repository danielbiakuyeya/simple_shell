#include "shell.h"

/**
 * set_env - set environment variable in the project
 * @args: arguments to be set in the project
 * Return: 1 on failure
 */

int set_env(char **args)
{
	char *error = "Usage: setenv VARIABLE VALUE\n";

	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		return (1);
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror(args[0]);
	}
	return (1);
}

/**
 * unset_env - unset enviroment variable in the project
 * @args: contains argument name to be unset in the project
 * Return: 1 on failure
 */

int unset_env(char **args)
{
	char *error = "Usage: unsetenv VARIABLE\n";

	if (args[1] == NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		return (1);
	}
	if (unsetenv(args[1]) != 0)
	{
		perror(args[1]);
	}
	return (1);
}
