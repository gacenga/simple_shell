#ifndef SHELL_H
#define SHELL_H

void display_prompt(void);
void execute_command(char *args[]);
int strtokn(char *input);
char *my_strdup(const char *str);

extern char **environ;

#endif
