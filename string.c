#include "simple_shell.h"
/**
 *_strdup - returns pointer to a newly allocated space
 *
 * @str: string which is to be copied
 *
 * Return: NULL if allocation fails, or if string is empty
 *		pointer to duplicate string otherwise.
 */
char *_strdup(char *str)
{
	unsigned int count, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	for (count = 0; str[count] != '\0'; count++)
	{
		;
	}

	dest = malloc((sizeof(char) * count) + 1);

	if (dest == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}

	dest[i] = '\0';

	return (dest);
}

/**
 *_strcat - function to concatenate 2 strings
 *
 * @dest: string to be appended
 * @src: string that is to be appended to
 *
 * Return: Returns the pointer to one of the strings passed
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
		;
	}
	for (j = 0; src[j] != '\0'; i++, j++)
	{
		dest[i] = src[j];
	}

	dest[i] = '\0';

	return (dest);
}

/**
 *_strcat66 - function to concatenate 2 strings
 *
 * @dest: string to be appended
 * @src: string that is to be appended to
 *
 * Return: Returns the pointer to one of the strings passed
 */
char *_strcat66(char *dest, char *src)
{
	int i, j;

	dest = "/";
	for (i = 0; dest[i] != '\0'; i++)
	{
		;
	}
	for (j = 0; src[j] != '\0'; i++, j++)
	{
		dest[i] = src[j];
	}

	dest[i] = '\0';

	return (dest);
}
/**
 * _strcmp - main function
 * @s1: first stirng
 * @s2: second string
 * Return: -, or 0
 */
int _strcmp(char *s1, char *s2)

{

	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)

		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
	return (0);
}
/**
 *_strlen - finds the length of a string
 *
 *@s: string of which the length is to be found
 *
 *Return: Returns an int which is the size of the string
 */
int _strlen(char *s)
{
	int length;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
