#include "simple_shell.h"

/**
 * fatd - free all the double pointers
 * @array: the array of double pointers
 * Return: void
 *
 * Description: This function frees the memory allocated for an array of
 * double pointers. It iterates through the array, freeing each individual
 * pointer, and finally frees the array itself.
 */
void fatd(char **array)
{
	int index;

	/* Check if the array is not NULL */
	if (!array)
	{
		return;
	}

	/* Iterate through the array, free each pointer, and set it to NULL */
	for (index = 0; array[index]; index++)
	{
		free(array[index]);
		array[index] = NULL;
	}

	/* Free the array itself and set it to NULL */
	free(array);
	array = NULL;
}

/**
 * displayerr - display the error message
 * @input: the input from the user
 * @Command: the command from the user
 * @indexx: the index of the command
 * Return: void
 *
 * Description: This function displays an error message to the standard error.
 * It takes the user input, command, and index as arguments, and prints an
 * error message indicating that the command was not found.
 */
void displayerr(char *input, char *Command, int indexx)
{
	char *i, error_message[] = ": not found\n";

	/* Convert the index to a string */
	i = integertostring(indexx);

	/* Write the error message to the standard error */
	write(STDERR_FILENO, input, strlen(input));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, Command, strlen(Command));
	write(STDERR_FILENO, error_message, strlen(error_message));

	/* Free the string representation of the index */
	free(i);
}

/**
 * integertostring - convert integer to string
 * @num: the number to convert
 * Return: the string
 *
 * Description: This function converts an integer to a string and returns
 * the string. It handles the case where the number is zero separately.
 * For example: 1234 -> "1234", 0 -> "0", 1234 -> "4321".
 */
char *integertostring(int num)
{ /* Convert integer to string */
	char storage[20];
	int index = 0;

	/* Handle the case where the number is zero separately */
	if (num == 0)
	{
		storage[index++] = '0';
	}
	else
	{
		/* Convert each digit to a character and reverse the string */
		while (num > 0)
		{
			storage[index++] = (num % 10) + '0';
			num /= 10;
		}
	}

	/* Null-terminate the string and reverse it */
	storage[index] = '\0';
	_strrev(storage, index);

	/* Return the duplicated string */
	return (strdup(storage));
}
