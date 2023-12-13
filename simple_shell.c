#include "simple_shell.h" 
/** 
 * main - Driver function for UNIX interpreter
 * @argc: void
 * @argv: void
 * @env: environment
 * Return: Returns (0) if successful, otherwise accoridng error.
 */
int main(int argc, char **argv, char **env)
{
		char *src = NULL;
		char **arr = NULL;
		char **env66 = NULL;
		size_t src_size = 0;
		int check = 0;
		(void)argc;
		(void)argv;

		while (check != -1)
		{
			signal(SIGINT, SIG_IGN);
			if (isatty(STDIN_FILENO))
				_printR("[(xshell$)] ");
			check = getline(&src, &src_size, stdin);
			src = strtok(src, "#");
			if (check == EOF && (isatty(STDIN_FILENO) == 0))
			{
				exit(EXIT_SUCCESS);
			}
			if (check == EOF)
			{
				_putchar('\n');
				exit(EXIT_SUCCESS);
			}
			src = newLine(src);
			if (check == 1)
				continue;
			arr = _tokenize(src);
			if (checkBuiltIn(arr, env) == 0)
			{
					continue;
			}
			env66 = DArrDup(env);
			getDirs(arr, env66);
			free(env66);
			free(arr);
			fflush(stdin);
		}

	return (0);
}
/**
 *_printR - prints the string passed to it
 *
 * @str: String that is passed to print
 *
 * Return: Number of strings written to stdout
 */
int _printR(char *str)
{
	int count;
	int val;

	for (count = 0; str[count]; count++)
		;

	val = write(STDOUT_FILENO, str, count);

	if (val != count)
	{
		write(STDERR_FILENO, "Write Error\n", 12);
		exit(EXIT_FAILURE);
	}

	return (val);
}
/**
 *getDirs - calls the right function from i/p command
 *
 * @input: Double array of input string
 * @Env: Double array of the environment
 *
 * Return:
 */
void getDirs(char **input, char **Env)
{
	char *pathofpath;
	char *convertedInput;
	char **tokenArr;
	char **concatArg;
	char **newArg;

	if (input[0][0] == '/')
	{
		if (access(input[0], X_OK) == 0)

		{
			if (functionExecute(input) != 0)
				exit(EXIT_FAILURE);
		}
		else
		{
			_printR("./hsh");
			_printR(": No such file or directory\n");
		}
	}
	else
	{
		pathofpath = getPath(Env);
		tokenArr = tokenizePath(pathofpath);
		concatArg = command_concat(input[0], tokenArr);
		convertedInput = checkPerm(concatArg);
		newArg = argDup(input, convertedInput);

		if (functionExecute1(newArg) != 0)
		{
			exit(EXIT_FAILURE);
		}
		free(tokenArr);
		free(concatArg);
		free(newArg);
	}
}
/**
 *functionExecute - Executes the function called
 *
 *@input: Pointer to pointers to input string
 *
 * Return: 0 on success, exits on failure
 */
int functionExecute(char **input)
{
	int status1;

	if (fork() == 0)
	{
		execve(input[0], input, NULL);
	}

	else
	{
		wait(&status1);
	}

	return (0);
}
/**
 *functionExecute1 - executes the function passed to it
 *
 * @input: Input string
 *
 * Return: 0 on success.
 */

int functionExecute1(char **input)
{
	int status1;

	if (fork() == 0)
	{
		execve(input[0], input, NULL);
	}

	else
	{
		wait(&status1);
	}
	return (0);
}
