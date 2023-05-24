#include "shell.h"

/**
 * my_strcpy - copies the string pointed to by src to by dest
 * @dest: ppointer to dest
 * @src: pointer to string
 * Return: return dest
 */
char *my_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * my_strcmp - Compares two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * Return: Negative value if s1 < s2, 0 if s1 == s2, positive value if s1 > s2.
 */
int my_strcmp(char *s1, char *s2)
{
	int i = 0, s = 0, st1 = 0, st2 = 0;

	i = 0;
	while (s1[st1] != '\0')
		st1++;
	while (s2[st2] != '\0')
		st2++;
	for (i = 0; i <= st1; i++)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
		{
			s = s1[i] - s2[i];
			break;
		}
		else
		{
			s = 0;
		}
	}
	return (s);
}

/**
 * my_strcat - concatenates two strings
 * @dest: Pointer to string
 * @src: Pointer to string
 * Return: Returns a pointer to the resulting string dest
 */
char *my_strcat(char *dest, char *src)
{
	int s, i;

	s = 0;
	while (dest[s] != '\0')
		s++;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[s + i] = src[i];
	}
	dest[i + s] = '\0';
	return (dest);
}

/**
 * my_strlen -  returns the length of a string
 * @s: pointer to a strint
 * Return: returns the length of a string
 */
int my_strlen(const char *s)
{
	int a;

	a = 0;
	for (; *s++;)
		a++;

	return (a);
}

/**
 * my_strcspn - calculates the length of the number of
 * characters before the 1st occurrence
 * @str: Pointer to the string to be searched.
 * @delim: Pointer to the string of delimiter characters.
 * Return: Length of the initial segment of str that has no
 * characters in delim.
 */
size_t my_strcspn(const char *str, const char *delim)
{
	const char *s = str;
	size_t count = 0;

	while (*s)
	{
		const char *d = delim;
		size_t i = 0;

		while (*d)
		{
			if (*s == *d)
			{
				return (count);
			}
			d++;
			i++;
		}
		s++;
		count++;
	}
	return (count);
}
