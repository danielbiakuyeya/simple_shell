#include "shell.h"

/**
 * cd - function to change directory in this project
 * @program_path: directory path in this project
 * Return: 0 on success
 */

int cd(char  *program_path)
{
	if (program_path == NULL)
		program_path = "/";
	if (_strcmp(program_path, "~") == 0)
		program_path = "/home";
	return (chdir(program_path));
}

/**
 * exit_shell - function to exit the shell
 * @status: exit status
 * Return: exit status
 */

int exit_shell(int status)
{
	exit(status);
}
