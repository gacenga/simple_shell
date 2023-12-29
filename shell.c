#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
/**
* main - simple shell
*
* Return:0 on success
*/
int main(void)
{
char input[MAX_INPUT_SIZE];
char *token;
display_prompt();
while (fgets(input, sizeof(input), stdin) != NULL)
{
input[strcspn(input, "\n")] = '\0';
token = strtok(input, ";");
while (token != NULL) {
if (strtokn(input))
{
exit(EXIT_SUCCESS);
break;
}
token = strtok(NULL, ";");
}
}
return (0);
}
