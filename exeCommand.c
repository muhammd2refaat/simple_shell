#include "simple_shell.h"

/**
 * exeCommand - execute the command
 * @theCMD: the command from the user
 * @argvector: the argument vector
 * @index: the index of the command
 * Return: 0 if success, 1 if fail
 */
int exeCommand(char **theCMD, char **argvector, int index)
{
	char *theGivenCommand;
	pid_t proccess_A;
	int condition;

	/* Resolve the full path for the given command */
	theGivenCommand = handle_path(theCMD[0]);
	/* Check if the command is valid */
	if (!theGivenCommand)
	{
		displayerr(argvector[0], theCMD[0], index);
		fatd(theCMD);
		return (127);
	}

	/* Create a child process using fork */
	proccess_A = fork();

	/* Check if it is the child process */
	if (proccess_A == 0)
	{
		/* Execute the command in the child process */
		if (execve(theGivenCommand, theCMD, environ) == -1)
		{
			/* If execve fails, free memory and terminate the child process */
			free(theGivenCommand), theGivenCommand = NULL;
			fatd(theCMD);
		}
	}
	else
	{
		/* Parent process: wait for the child process to complete */
		waitpid(proccess_A, &condition, 0);
		fatd(theCMD);
		free(theGivenCommand), theGivenCommand = NULL;
	}

	/* Return the exit status of the child process */
	return (WEXITSTATUS(condition));
}
