#include "shell.h"

/**
 * get_alaises - parse the argument to alias in the project
 * @str: string to be parsed in the project
 * Return: Null on failure, else return array of arguments
 */

char **get_alaises(char *str)
{
	char **arguments, *argument, *parse;
	char *delimiter = " \t\r\n";
	long int index = 0;
	int arg_len = 0;
	char *str_copy = _strdup(str);

	if (str == NULL || str_copy == NULL)
	{
		free(str_copy);
		return (NULL);
	}
	parse = _strtok(str_copy, delimiter);
	while (parse != NULL)
	{
		arg_len++;
		parse = _strtok(NULL, delimiter);
	}
	arguments = malloc(sizeof(char *) * (arg_len + 1));
	if (arguments == NULL)
	{
		free(arguments);
		free(str_copy);
		return (NULL);
	}
	argument = _strtok(str, delimiter);
	while (argument != NULL)
	{
		arguments[index] = argument;
		argument = _strtok(NULL, delimiter);
		index++;
	}
	arguments[index] = NULL;
	free(str_copy);
	return (arguments);
}
