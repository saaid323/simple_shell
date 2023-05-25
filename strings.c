#include "shell.h"

/**
 * _strcmp - Compares two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * Return: Negative value if s1 < s2, 0 if s1 == s2, positive value if s1 > s2.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strcat - concatenates two strings
 * @dest: Pointer to string
 * @src: Pointer to string
 * Return: Returns a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *new_string =  NULL;
	int len_dest = _strlen(dest);
	int len_source = _strlen(src);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(dest, new_string);
	_strcpy(src, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}

/**
 * _strspn - Get the length of a prefix substring
 * @str1: Input string
 * @str2: String containing characters to match
 *
 * Return: Number of characters in str1 that consist of characters from str2
 */

int _strspn(char *str1, char *str2)
{
	int i = 0;
	int match = 0;

	while (str1[i] != '\0')
	{
		if (_strchr(str2, str1[i]) == NULL)
			break;
		match++;
		i++;
	}
	return (match);
}

/**
 * _strcspn - Get the length of a prefix substring excluding certain characters
 * @str1: Input string
 * @str2: String containing characters to exclude
 * Return: Number of characters in str1 until the first occurrence
 * of any character from str2
 */

int _strcspn(char *str1, char *str2)
{
	int len = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (_strchr(str2, str1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}

/**
 * _strchr - Locate the first occurrence of a character in a string
 * @s: Input string
 * @c: Character to locate
 * Return: Pointer to the first occurrence of the character c in
 * the string s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
