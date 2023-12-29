#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024

int cd_builtin(char *args[])
{
  char cwd[MAX_INPUT_SIZE];
  if (args[1] == NULL) {
        const char *home = getenv("HOME");
        if (home != NULL) {
            if (chdir(home) == -1) {
                perror("cd");
                return 1; 
            }
        }
    } else if (strcmp(args[1], "-") == 0) {
        
        const char *oldpwd = getenv("OLDPWD");
        if (oldpwd != NULL) {
            if (chdir(oldpwd) == -1) {
                perror("cd");
                return 1;
            }
        }
    } else {
        
        if (chdir(args[1]) == -1) {
            perror("cd");
            return 1;
        }
    }

    
   
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("cd");
        return 1; 
    }

    if (setenv("PWD", cwd, 1) == -1) {
        perror("cd");
        return 1; 
    }

    return 0; 
}
