#include "shell.h"

/**
 * check_builtins - check if command is a builtin in the project
 * @commands: array of commands args in the project
 * Return: 1 on success, 0 if unsuccessful
 */

int check_builtins(char **commands)
{
	char current_pwd[1024];

	if (_strcmp(commands[0], "cd") == 0)
	{
		if (cd(commands[1]) < 0)
			perror(commands[1]);
		if (getcwd(current_pwd, sizeof(current_pwd)) != NULL)
			setenv("PWD", current_pwd, 1);
		return (1);
	}
	if (_strcmp(commands[0], "setenv") == 0)
	{
		if (set_env(commands) == 1)
			return (1);
	}

	if (_strcmp(commands[0], "unsetenv") == 0)
	{
		if (unset_env(commands) == 1)
			return (1);
	}
	if (_strcmp(commands[0], "exit") == 0)
	{
		if (commands[1] == NULL)
			exit_shell(EXIT_SUCCESS);
		else
			exit_shell(_atoi(commands[1]));
	}
	if (_strcmp(commands[0], "env") == 0)
		if (print_env() == 1)
			return (1);

	if (access(commands[0], F_OK | X_OK) == 0)
	{
		execute_command(commands[0], commands);
		return (1);
	}
	return (0);
}
