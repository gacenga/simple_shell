#ifndef SIMPLESHELL
#define SIMPLESHELL
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
sighandler_t ignore;
char *_strdup(char *str);
char **_tokenize(char *str);
int _putchar(char c);
int _printR(char *str);
char *newLine(char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *pathFind(char **Enviro);
void getDirs(char **input, char **Env);
char *getPath(char **envi);
char **tokenizePath(char *inPath);
char **command_concat(char *string1, char **dblArr);
int _strlen(char *s);
char *inputConverter(char *inputStr);
char *checkPerm(char **dirsWithSlash);
char **argDup(char **ip, char *newArg);
char **DArrDup(char **src);
int functionExecute1(char **input);
int functionExecute(char **input);
int _env(int argc, char **argv, char **envp);
int checkBuiltIn(char **array, char **ENN);
int printenv(char **ENNV);
void _freeArr(char **doubleArray);
#endif
