#include "shell.h"

/**
 * _strtok - Tokenize a string
 * @str: Input string to be tokenized
 * @deli: Delimiter string
 * @t: Double pointer to track the current position in the string
 *
 * Return: Pointer to the next token in the string
 */
char *_strtok(char *str, char *deli, char **t)
{
	char *end;

	if (str == NULL)
		str = *t;
	if (*str == '\0')
	{
		*t = str;
		return (NULL);
	}
	str += _strspn(str, deli);
	if (*str == '\0')
	{
		*t = str;
		return (NULL);
	}
	end = str + _strcspn(str, deli);
	if (*end == '\0')
	{
		*t = end;
		return (str);
	}
	*end = '\0';
	*t = end + 1;
	return (str);
}

/**
 * _strcpy - copies the string pointed to by src to by dest
 * @dest: ppointer to dest
 * @src: pointer to string
 */
void _strcpy(char *src, char *dest)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * _strlen -  returns the length of a string
 * @s: pointer to a strint
 * Return: returns the length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (len);
	for (; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * my_realloc - Reallocate memory
 * @ptr: Pointer to the memory block to be reallocated
 * @old: Old size of the memory block
 * @new_: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 */

void *my_realloc(void *ptr, unsigned int old, unsigned int new_)
{
	void *temp;
	unsigned int i;

	if (ptr == NULL)
	{
		temp = malloc(new_);
		return (temp);
	}
	else if (new_ == old)
		return (ptr);
	else if (new_ == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp = malloc(new_);
		if (temp != NULL)
		{
			for (i = 0; i < min(old, new_); i++)
				*((char *)temp + i) = *((char *)ptr + i);
			free(ptr);
			return (temp);
		}
		else
			return (NULL);
	}
}

/**
 * newline - Replace newline character with null character
 * @str: Input string
 */

void newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}
