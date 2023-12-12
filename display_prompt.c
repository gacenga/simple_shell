#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
* display_prompt - displays #cisfun$
*
* Return:void
*/
void display_prompt(void)
{
printf("#cisfun$ ");
fflush(stdout);
}
