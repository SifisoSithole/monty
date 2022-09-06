#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _realloc - function that reallocates a memory
 * @ptr: memory to resize
 * @old_size: old size of the array
 * @new_size: new size of the array
 *
 * Return: Pointer to the new array
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tempArr;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
	{
		tempArr = malloc(new_size);
		if (!tempArr)
			return (NULL);
		return (tempArr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	tempArr = malloc(new_size);
	if (!tempArr)
		return (NULL);
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			tempArr[i] = ((char *)ptr)[i];
	}
	else
	{
		for (i = 0; i < new_size; i++)
			tempArr[i] = ((char *)ptr)[i];
	}

	free(ptr);
	return (tempArr);
}

/**
 * _getline - This function reads line from a stream
 * @lineptr: Buffer to store string
 * @n: Size of buffer
 * @stream: File pointer
 *
 * Return: Number of lines read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char buffer[128];

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*n = sizeof(buffer);
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	(*lineptr)[0] = '\0';
	while ((fgets(buffer, sizeof(buffer), stream)) != NULL)
	{
		if (*n - strlen(*lineptr) < sizeof(buffer))
		{
			*lineptr = _realloc(*lineptr, *n, *n * 2);
			*n *= 2;
			if (*lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
		}
		strcat(*lineptr, buffer);
		if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
			return (strlen(*lineptr));
	}
	return (-1);
}
