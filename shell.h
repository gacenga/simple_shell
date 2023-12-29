#ifndef SHELL_H
#define SHELL_H

void display_prompt(void);
void execute_command(char *args[]);
int strtokn(char *input);
char *my_strdup(const char *str);
int setenv_builtin(char *args[]);
int unsetenv_builtin(char *args[]);
int cd_builtin(char *args[]);

extern char **environ;

#endif
