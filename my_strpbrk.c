#include "shell.h"

/**
 * my_strpbrk - Finds the first occurrence of character in str.
 * @str: Pointer to the string to be searched.
 * @delim: Pointer to the string of delimiter characters.
 * Return: Pointer to str, or NULL if not found.
 */
char *my_strpbrk(const char *str, const char *delim)
{
	while (*str)
	{
		const char *d = delim;

		while (*d)
		{
			if (*str == *d)
			{
				return ((char *)str);
			}
			d++;
		}
		str++;
	}
	return (NULL);
}
