#include "shell.h"

/**
 * concatenate_format - concantenate the path with the program name
 * @str1: path of the program in shell
 * @str2: program name in shell
 * Return: Null if fail, else return a pointer to the concatenated
 * program path
 */

char *concatenate_format(char *str1, char *str2)
{
	int i, j;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str1) + _strlen(str2) + 2));

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; str1[i] != '\0'; i++)
	{
		buff[i] = str1[i];
	}
	buff[i] = '/';
	for (j = 0; str2[j] != '\0'; j++)
	{
		buff[i + 1] = str2[j];
		i++;
	}
	buff[i + 1] = '\0';
	return (buff);
}
