#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE   64
#define MAX_ARG_COUNT  16
/**
* strtokn - tokenise string
* @input:input
* Return:void
*/
void strtokn(char *input)
{
char *args[MAX_ARG_COUNT];
int arg_count = 0;
char **env;
char *token;
char input_copy[MAX_INPUT_SIZE];
strncpy(input_copy, input, sizeof(input_copy) - 1);
input_copy[sizeof(input_copy) - 1] = '\0';
token = strtok(input_copy, " ");
while (token != NULL && arg_count < MAX_ARG_COUNT)
{
args[arg_count++] = token;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
if (arg_count > 0)
{
if (strcmp(args[0], "exit") == 0)
{
printf("Exiting shell.\n");
exit(EXIT_SUCCESS);
}
else if (strcmp(args[0], "env") == 0)
{
env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
else
{
execute_command(args);
}
}
arg_count = 0;
}
