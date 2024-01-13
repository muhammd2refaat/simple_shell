#include "simple_shell.h"

/**
 * ls_Bltn - check if the command is builtin
 * @Cmd: the command to check
 * Return: 1 if the command is builtin, 0 if not
 *
 * Description: This function checks
 * if the given command is a built-in command.
 * It compares the command with
 * a predefined list of built-in commands and returns
 * 1 if the command is found in the list, otherwise returns 0.
 */
int ls_Bltn(char *Cmd)
{ /* Check if the command is a built-in command */
	int i;
	char *bltnIs[] = {"exit", "env", "setenv", "cd", NULL};

	for (i = 0; bltnIs[i]; i++)
	{ /* Compare the command with each built-in command in the list */
		if (strcmp(Cmd, bltnIs[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * bltn_Hand - handle the builtin command
 * @Cmd: the command to handle
 * @argVector: the argument vector
 * @stuts: the status of the shell
 * @index: the index of the command
 * Return: void
 *
 * Description: This function handles the execution of built-in commands.
 * It takes the command, argument vector, status, and index as parameters and
 * performs the appropriate action based on the built-in command.
 */
void bltn_Hand(char **Cmd, char **argVector, int *stuts, int index)
{ /* Handle the execution of built-in commands */
	if (strcmp(Cmd[0], "exit") == 0)
	{ /* Terminate the shell */
		terminateShell(Cmd, argVector, stuts, index);
	}
	else if (strcmp(Cmd[0], "env") == 0)
	{ /* Display environment variables */
		display_enviroment_variable(Cmd, stuts);
	}
}

/**
 * terminateShell - terminate the shell
 * @Cmd: the command to terminate
 * @argVector: the argument vector
 * @stuts: the status of the shell
 * @indexx: the index of the command
 * Return: void
 *
 * Description: This function terminates
 * the shell. If the exit command is followed
 * by a numeric argument, it attempts
 * to convert it to an integer and uses it as the
 * exit status. If the argument is not a valid integer,
 * a positive integer, it displays an error message
 * and sets the exit status to 2.
 */
void terminateShell(char **Cmd, char **argVector, int *stuts, int indexx)
{ /* Terminate the shell */
	int output = (*stuts);
	char error_Message[] = ": exit: Illegal number: ";
	char *i;

	if (Cmd[1])
	{ /* Check if an argument is provided */
		if (checkifthegivennumberispostive(Cmd[1]))
		{ /* Convert the argument to an integer if it is a positive number */
			output = stringtointeger(Cmd[1]);
		}
		else
		{ /* Display an error message for an invalid exit status argument */
			i = integertostring(indexx);
			write(STDERR_FILENO, argVector[0], strlen(argVector[0]));
			/* Write the error message to the standard error */
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, i, strlen(i));
			write(STDERR_FILENO, error_Message, strlen(error_Message));
			write(STDERR_FILENO, Cmd[1], strlen(Cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(i);
			fatd(Cmd);
			(*stuts) = 2;
			return;
		}
	}

	fatd(Cmd);
	exit(output);
}

/**
 * display_enviroment_variable - display the environment variable
 * @Cmd: the command to display
 * @stuts: the status of the shell
 * Return: void
 *
 * Description: This function displays the
 * environment variables to the standard output.
 */
void display_enviroment_variable(char **Cmd, int *stuts)
{ /* Display environment variables */
	int i;

	for (i = 0; environ[i]; i++)
	{ /* Print each environment variable */
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	fatd(Cmd);
	(*stuts) = 0;
}
