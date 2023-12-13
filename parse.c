#include "simple_shell.h"
/**
 *_tokenize - function to tokenize i/p string
 *
 *  @str: Input string
 *
 *  Return: Double pointer to arrays of tokens
 */
char **_tokenize(char *str)
{
		char *cp1 = _strdup(str);
		char *token;
		int count = 0, i = 0;
		char **store = NULL;

		if (cp1 == NULL)
		{
			printf("Failed to tokenize!\n");
				return (NULL);
		}
		token = strtok(cp1, " ");
		while (token != NULL)
		{
			token = strtok(NULL, " ");
				count++;
		}
		store = malloc(sizeof(char *) * (count + 1));
		if (store == NULL)
		{
			printf("Failed to tokenize!\n");
				return (NULL);
		}
		token = strtok(str, " ");
		while (token != NULL)
		{
			store[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		store[count] = NULL;
		free(cp1);
		return (&store[0]);
}

/**
 *_freeArr - Frees individual arrays in a double array
 *
 * @doubleArray: Double array passed to free
 *
 * Return: No return
 */
void _freeArr(char **doubleArray)
{
	int i = 0;

	for (i = 0; doubleArray[i] != NULL; i++)
	{
		free(doubleArray[i]);
	}
}
