#include "simple_shell.h"

/**
 * handle_path - handle the path
 * @cmd: the command
 * Return: the path
 * Description: This function handles the path resolution for a given command.
 * It checks if the command contains a '/' character. If it does, it checks if
 * the file exists and returns a duplicate of the command if it does, otherwise
 * returns NULL.If the command doesn't contain '/', it searches for the command
 * in directories listed in the PATH environment variable.
 * It returns the full path
 * of the command if found, otherwise returns NULL.
 *
 * Example:
 *   handle_path("ls") -> "/bin/ls"
 *   handle_path("ls") -> "/usr/local/bin/ls"
 */
char *handle_path(char *cmd)
{ /* Declarations */
	char *pthEnv, *fullCommand, *diective;
	struct stat status;
	int counter;
	/* Check if the command contains a '/' character */
	for (counter = 0; cmd[counter]; counter++)
	{ /*If the '/' character is found, check if the command is an absolute path */
		if (cmd[counter] == '/')
		{ /* If the file exists, return a duplicate of the command */
			if (stat(cmd, &status) == 0)
				return (strdup(cmd));
			return (NULL); /* If the file does not exist, return NULL */
		}
	} /* Get the PATH environment variable */
	pthEnv = enviro_variable("PATH");
	if (!pthEnv) /* Return NULL if PATH is not set */
		return (NULL);
	/* Tokenize the PATH into directories */
	diective = strtok(pthEnv, ":");
	/* Iterate through the directories in PATH */
	while (diective)
	{ /* Create a full command path by concatenating directory and command */
		fullCommand = malloc(strlen(diective) + strlen(cmd) + 2);
		/* Check if memory allocation is successful */
		if (fullCommand)
		{ /* Construct the full command path */
			strcpy(fullCommand, diective);
			strcat(fullCommand, "/");
			strcat(fullCommand, cmd);
			if (stat(fullCommand, &status) == 0)
			{ /* If the file exists, free PATH and return the full command path */
				free(pthEnv);
				return (fullCommand);
			} /* Free the full command path for the next iteration */
			free(fullCommand);
			fullCommand = NULL;
			diective = strtok(NULL, ":");
		}
	} /* Free the PATH string and return NULL if the command is not found. */
	free(pthEnv);
	return (NULL);
}
