#include "shell.h"

/**
 * execute_file - function that execute shell commands in none interactive mode
 * @file_name: file name argument to the shell in shell
 * Return: Always Nothing
 */

void execute_file(char *file_name)
{
	char *line_copy, *command_error = "No Commands Found\n";
	char *PATH = NULL, **commands = NULL, line[MAX_LINE_LENGHT];
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGHT, file) != NULL)
	{
		line_copy = _strdup(line);
		commands = get_arguments(line, " :\t\r\n");
		check_null(commands, command_error);
		if (line[0] == '#')
		{
			free(line_copy);
			free(commands);
			continue;
		}
		else
		{
			if (check_continue(line_copy, commands) == 1)
				continue;
			PATH = check_env_path(commands[0]);
			if (PATH == NULL)
			{
				perror(commands[0]);
				free_all(PATH, line_copy, commands);
				continue;
			}
			execute_command(PATH, commands);
			if (commands != NULL)
				free_all(PATH, line_copy, commands);
		}
	}
	fclose(file);
}
