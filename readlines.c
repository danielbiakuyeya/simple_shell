#include "shell.h"

/**
 * read_line - read input from the stdin in the project
 * Return: Null if an error occour else return
 */

char **read_line()
{
	char **buffer;
	size_t str;
	size_t MAX_LENGHT = MAX_LINE_LENGHT;

	buffer = calloc(MAX_LENGHT, sizeof(char *));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	str = _getline(buffer, &MAX_LENGHT, stdin);
	if (str <= 0)
	{
		return (NULL);
	}
	while (str > MAX_LENGHT - 1)
	{
		MAX_LENGHT *= 2;
		buffer = realloc(buffer, MAX_LENGHT);
		if (buffer == NULL)
			return (NULL);
		str = _getline(buffer, &MAX_LENGHT, stdin);
		if (str == (size_t) -1)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (buffer);
}

/**
 * _strtok - delimites strings into tokens in the project
 * @str: string to be delimited in the project
 * @delim: character to be used as the delimiter in the project
 * Return: Null in failure; else return tokened string
 */

char *_strtok(char *str, char *delim)
{
	static char *last_token;
	char *token;
	char *delim_pos;

	if (str != NULL)
	{
		last_token = str;
	}
	else if (last_token == NULL)
	{
		return (NULL);
	}
	token = last_token;
	while (*token && _strchr(delim, *token))
	{
		token++;
	}
	if (*token)
	{
		delim_pos = _strpbrk(token, delim);
		if (delim_pos)
		{
			*delim_pos = '\0';
			last_token = delim_pos + 1;
		}
		else
		{
			last_token = NULL;
		}
	}
	else
	{
		token = NULL;
	}
	return (token);
}
