#include "shell.h"

/**
 * get_arguments - split the str to various path to be
 * passed to the the program in the project
 * @str: command string from the user in the project
 * @delimiter: determins how the character should be parsed in the project
 * Return: Null if fails, or array of arguments when
 * successful
 */

char **get_arguments(char *str, char *delimiter)
{
	char **arguments, *argument, *parse;
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
