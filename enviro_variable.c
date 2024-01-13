#include "simple_shell.h"

/**
 * enviro_variable - get the environment variable
 * @var: the variable
 * Return: the environment variable
 */
char *enviro_variable(char *var)
{
	char *temprory, *one_Key, *amount, *environment;
	int i;

	/* Iterate through the environment variables */
	for (i = 0; environ[i]; i++)
	{
		/* Create a temporary copy of the current environment variable */
		temprory = strdup(environ[i]);

		/* Extract the key (before '=') from the environment variable */
		one_Key = strtok(temprory, "=");

		/* Check if the key matches the specified variable */
		if (strcmp(one_Key, var) == 0)
		{
			/* Extract the value (after '=') of the environment variable */
			amount = strtok(NULL, "\n");
			environment = strdup(amount);

			/* Free the temporary copy and return the environment variable */
			free(temprory);
			return (environment);
		}

		/* Free the temporary copy for the next iteration */
		free(temprory);
		temprory = NULL;
	}

	/* Return NULL if the variable is not found in the environment */
	return (NULL);
}
