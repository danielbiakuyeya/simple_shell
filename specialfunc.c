#include "shell.h"

/**
 * special_case_semi - function to handle the ";" command simple shell project
 * @str: string to be parsed in simple shell project
 * Return: 1 on success, 0 on failure
 */

int special_case_semi(char *str)
{
	char **commands = NULL;
	char *path = NULL;
	char **semi_separated = get_arguments(str, ";");
	int i = 0;

	if (semi_separated == NULL || *semi_separated == NULL)
	{
		free_me(semi_separated);
		return (1);
	}
	while (semi_separated[i] != NULL)
	{
		commands = get_arguments(semi_separated[i], " :\t\r\n");
		if (check_builtins(commands) == 1)
		{
			i++;
			free(commands);
			continue;
		}
		path = check_env_path(commands[0]);
		if (path != NULL)
		{
			execute_command(path, commands);
			if (path != NULL)
				free(path);
		}
		else
			perror(commands[0]);
		free(commands);
		i++;
	}
	free(semi_separated);
	return (0);
}
