#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


/* getInputFromUser - get the input from the user */
char *getInputFromUser(void);
/* fatd - free all the double pointers */
void fatd(char **arr);
/* exeCommand - execute the command */
int exeCommand(char **command, char **argv, int idx);
/* string_tokinizer - tokinize the string */
char **string_tokinizer(char *line);
/* enviro_variable - get the environment variable */
char *enviro_variable(char *variable);
/* handle_path - handle the path */
char *handle_path(char *command);
/* displayerr - display the error message */
void displayerr(char *name, char *cmd, int idx);
/* integertostring - convert integer to string */
char *integertostring(int number);
/* _strrev - reverse the string */
void _strrev(char *str, int length);
/* ls_Bltn - check if the command is builtin */
int ls_Bltn(char *command);
/* bltn_Hand - handle the builtin command */
void bltn_Hand(char **Cmd, char **argVector, int *stuts, int index);
/* terminateShell - terminate the shell */
void terminateShell(char **command, char **argv, int *status, int idx);
/* display_enviroment_variable - display the environment variable */
void display_enviroment_variable(char **command, int *status);
/* stringtointeger - convert string to integer */
int stringtointeger(char *str);
/* checkifthegivennumberispostive - check if the given number is postive */
int checkifthegivennumberispostive(char *str);

#define  theDelimiter " \t\n"


extern char **environ;






#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>

#endif
