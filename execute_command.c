#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
* execute_command - execute command
*
* @args:arguments
* Return:void
*/
void execute_command(char *args[])
{
pid_t pid = fork();
int status;
if (pid == -1)
{
fprintf(stderr, "./hsh: %d: fork failed\n", __LINE__);
exit(EXIT_FAILURE);
}
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
fprintf(stderr, "./hsh: %d: %s: not found\n", __LINE__, args[0]);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
}
