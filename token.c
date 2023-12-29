#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT  16
/**
* strtokn - tokenise string
* @input:input
* @should_sxit:pointer
* Return:void
*/
int strtokn(char *input)
{
int i;
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
args[arg_count++] = my_strdup(token);
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
if (arg_count > 0)
{
if (strcmp(args[0], "exit") == 0)
{
for (i = 0; i < arg_count; ++i)
{
free(args[i]);
args[i] = NULL;
}
return 1;
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
else if (strcmp(args[0], "setenv") == 0)
{
if (arg_count != 3)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
}
else
{
setenv_builtin(args);
}
}
else if (strcmp(args[0], "unsetenv") == 0)
{
if (arg_count != 2)
{
fprintf(stderr, "Usage: unsetenv VARIABLE\n");
}
else
{
unsetenv_builtin(args);
}
}
else
{
execute_command(args);
}
}
for (i = 0; i < arg_count; ++i)
{
free(args[i]);
args[i] = NULL;
}
return (0);
}
