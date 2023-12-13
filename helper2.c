#include "simple_shell.h"
/**
 *checkBuiltIn - checks for the built in functions
 * @array: Double array of pointers to i/p strings
 * @ENN: Pointer to pointers of environment variables
 * Return: Returns nothing
 */
int checkBuiltIn(char **array, char **ENN)
{	
	int a = 0;
	
	if (_strcmp("exit", array[0]) == 0)
	{
		free(array);
		exit(EXIT_SUCCESS);
	}

	if (_strcmp(array[0], "env") == 0)
	{
		a = printenv(ENN);
		return (a);
	}
	
	return (1);
}

/**
 * printenv - prints the environment passed
 * @ENNV: environment passed
 * Return: void
 */
int printenv(char **ENNV)
{
		int i = 0;

		for (i = 0; ENNV[i] != NULL; i++)
		{
			_printR(ENNV[i]);
			_putchar('\n');
		}

		return (0);
}
/**
 * newLine - converts encountered new line into NULL byte
 *
 * @src: String that is passed
 *
 * Return: String with null termination
 */
char *newLine(char *src)
{
	int j = 0;

	for (j = 0; src[j] != '\0'; ++j)
	{
		if (src[j] == '\n' || src[j + 1] == '\0')
			src[j] = '\0';
	}
	return (src);
}
/**
 * getPath - function to get the path of PATH
 *
 * @envi: Pointer to environment variables
 *
 * Return: Path of path on success (Always success as PATH always exists)
 */
char *getPath(char **envi)
{
	int i, compcheck = 0;

	for (i = 0; envi[i] != NULL; i++)
	{
		compcheck = _strcmp("PATH", strtok(envi[i], "="));
		if (compcheck == 0)
		{
			break;
		}
	}

	return (strtok(NULL, "\0"));
}
