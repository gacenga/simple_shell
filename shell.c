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
* main - simple shell
*
* Return:0 on success
*/
int main(void)
{
char input[MAX_INPUT_SIZE];
while (1)
{
display_prompt();
if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}
input[strcspn(input, "\n")] = '\0';
strtokn(input);
}
return (0);
}
