#include "simple_shell.h"
/**
 * string_tokinizer - tokinize the string
 * @given_commandFrom_User: the command from the user
 * Return: the tokinized string
*/
char **string_tokinizer(char *given_commandFrom_User)
{	/* Declare the variables */
	char *string = NULL, *temprory_variable = NULL;
	char **CMD = NULL;
	int indexOfTheNextToken = 0, index = 0;
	/* Check if the command is NULL */
	if (!given_commandFrom_User)
	{
		return (NULL);
	} /* Check if the command is empty */
	temprory_variable = strdup(given_commandFrom_User);
	string = strtok(temprory_variable, theDelimiter);
	if (string == NULL)
	{ /* Check if the command is empty */
		free(given_commandFrom_User), given_commandFrom_User = NULL;
		free(temprory_variable), temprory_variable = NULL;
		return (NULL);
	} /* Count the number of tokens */
	while (string)
	{ /* Count the number of tokens */
		indexOfTheNextToken++;
		string = strtok(NULL, theDelimiter);
	} /* Check if the command is empty */
	free(temprory_variable), temprory_variable = NULL;
	CMD = malloc(sizeof(char *) * (indexOfTheNextToken + 1));
	if (!CMD)
	{ /* Check if the command is empty */
		free(given_commandFrom_User);
		return (NULL);
	}
	string = strtok(given_commandFrom_User, theDelimiter);
	while (string)
	{ /* Count the number of tokens */
		CMD[index] = strdup(string);
		string = strtok(NULL, theDelimiter);
		index++;
	}
	free(given_commandFrom_User), given_commandFrom_User = NULL;
	CMD[index] = NULL;
	return (CMD); /* Return the tokinized string */
}
