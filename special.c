#include "shell.h"

/**
 * check_special - function to handle special cases in the project
 * @input: input to be parsed for special characters before
 * execution in the project
 * Return: 1 on success, 0 on failure
 */

int check_special(char *input)
{
	int status = 0;
	int fork_pid = getpid();
	char buffer_status[MAX_LINE_LENGHT];
	char buffer_pid[MAX_LINE_LENGHT];

	int_to_string(buffer_status, status);
	int_to_string(buffer_pid, fork_pid);

	if (_strchr(input, ';') != NULL)
	{
		special_case_semi(input);
		return (1);
	}
	if (_strcmp(input, "echo $?\n") == 0)
	{
		write(STDERR_FILENO, buffer_status, _strlen(buffer_status));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	if (_strcmp(input, "echo $$\n") == 0)
	{

		write(STDERR_FILENO, buffer_pid, _strlen(buffer_pid));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}
