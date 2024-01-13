#include "simple_shell.h"

/**
 * getInputFromUser - get the input from the user
 * Return: the input from the user
 */
char *getInputFromUser(void)
{
	char *user_input = NULL;
	size_t input_lenght = 0;
	ssize_t ifFails;

	/* Display prompt only if the input is coming from a terminal */
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	/* Read user input using getline */
	ifFails = getline(&user_input, &input_lenght, stdin);

	/* Check if getline fails (returns -1) and free memory if needed */
	if (ifFails == -1)
	{
		free(user_input);
		return (NULL);
	}

	/* Return the user input */
	return (user_input);
}
