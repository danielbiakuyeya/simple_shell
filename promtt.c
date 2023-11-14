#include "shell.h"

/**
 * shell_prompt - display the prompt message in the project
 * Return: Always nothing
 */

void shell_prompt(void)
{
	int isatty_in = isatty(STDIN_FILENO);
	int isatty_out = isatty(STDOUT_FILENO);

	if (isatty_in && isatty_out)
	{
		write(STDERR_FILENO, "$ ", 2);
	}
}
