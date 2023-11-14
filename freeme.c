#include "shell.h"

/**
 * free_me - free a 2d pointer memory address in the project
 * @ptr: pointer to address in the project
 * Return: Always Nothing
 */

void free_me(char **ptr)
{
	int i = 0;

	if (!ptr || ptr == NULL)
		return;
	while (ptr[i] != NULL)
	{
		if (ptr[i] != NULL)
		{
			free(ptr[i]);
		}
		i++;
	}
	free(ptr);
}
