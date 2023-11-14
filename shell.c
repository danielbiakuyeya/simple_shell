#include "shell.h"

/**
 * main - main Entry into the program in the project
 * @argc: total number of arguments in the project
 * @argv: array of argument variable in the project
 * @envp: environment variables in the project
 * Return: Nothing
 */

int main(int argc, char **argv, char *envp[])
{
	char *PATH, *input_alias;
	char **commands = NULL, **input = NULL;
	(void)argv, (void)envp;

	if (argc == 2)
		execute_file(argv[1]);
	else
	{
		signal(SIGINT, handle_signals_C);
		while (1)
		{
			if (commands != NULL)
				free_all_main(commands, input_alias, input);
			shell_prompt();
			input = read_line();
			if (input == NULL)
				exit(0);
			input_alias = _strdup(*input);
			commands = get_arguments(*input, " :\t\r\n");
			if (commands == NULL || *commands == NULL || **commands == '\0'
					|| input_alias[0] == '#')
				continue;
			if (check_special(input_alias) == 1 || check_builtins(commands) == 1
					|| check_alias(input_alias) == 1)
				continue;
			PATH = check_env_path(commands[0]);
			if (PATH != NULL)
			{
				execute_command(PATH, commands);
				if (PATH != NULL)
					free(PATH);
			}
			else
				perror(argv[0]);
		}
	}
	return (0);
}
