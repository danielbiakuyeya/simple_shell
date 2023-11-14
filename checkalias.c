#include "shell.h"

/**
 * check_alias - check if first word of input is alias in the project
 * @input: input to be parsed in the project
 * Return: 1 on success, 0 on failure
 */

char check_alias(char *input)
{
	int len = 0;
	char **commands = NULL;
	alias alias_default[] = {
		{"egrep", "egrep --color=auto"},
		{"fgrep", "fgrep --color=auto"},
		{"grep", "grep --color=auto"},
		{"l", "ls -CF"},
		{"la", "ls -A"},
		{"ll", "ls -alF"},
		{"ls", "ls --color=auto"},
		{NULL, NULL}
	};
	commands = get_alaises(input);
	len = _strlen(commands[0]);
	if (len > 0 && commands[0][len - 1] == '\n')
	{
		commands[0][len - 1] = '\0';
	}
	if (_strcmp(commands[0], "alias") == 0)
	{
		if (commands[1] == NULL)
		{
			print_alias(alias_default);
		}
		else if (commands[1] != NULL)
		{
			;
		}
		free(commands);
		return (1);
	}
	free(commands);
	return (0);
}
