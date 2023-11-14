#include "shell.h"

/**
 * check_env_path - check if the command exit in the project
 * @command: command name in the project
 * Return: NULL on failure, else return path
 */

char *check_env_path(char *command)
{
	char *dir, *program_path;
	char *sys_path = getenv("PATH");
	char *sys_path_copy = _strdup(sys_path);
	char *command_copy = _strdup(command);
	int i = 0;

	if (sys_path_copy == NULL)
		return (NULL);
	if (sys_path == NULL)
		return (NULL);
	dir = _strtok(sys_path_copy, ":");
	while (dir != NULL)
	{
		program_path = concatenate_format(dir, command_copy);
		if (access(program_path, F_OK | X_OK) == 0)
		{
			free(sys_path_copy);
			free(command_copy);
			return (program_path);
		}
		free(program_path);
		dir = _strtok(NULL, ":");
		i++;
	}
	free(sys_path_copy);
	free(command_copy);
	return (NULL);
}
