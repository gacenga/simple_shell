#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int setenv_builtin(char *args[])
{
    if (setenv(args[1], args[2], 1) == -1)
    {
        perror("setenv");
        return 1;
    }

    return 0; 
}

int unsetenv_builtin(char *args[])
{
    if (unsetenv(args[1]) == -1)
    {
        perror("unsetenv");
        return 1;
    }

    return 0; 
}
