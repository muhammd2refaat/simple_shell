#include "simple_shell.h"

/**
 * main - the main function of the shell
 * @argument_counter: the number of arguments
 * @argument_vector: the argument vector
 * Return: 0 if success, 1 if fail
 *
 * Description: This is the main function of the shell. It repeatedly prompts
 * the user for input, processes the input,
 * and executes commands until the user
 * decides to exit the shell. It utilizes various helper functions for input,
 * tokenization, and command execution.
 */
int main(int argument_counter, char **argument_vector)
{ /* Main function of the shell */
	char *given_CommandFromUser = NULL; /* Store the user input */
	char **CMD = NULL; /* Store the tokenized command */
	int condition = 0, index = 0; /* Status and command index */
	(void)argument_counter; /* Avoid unused variable warning */

	while (1)
	{ /* Main shell loop */
		given_CommandFromUser = getInputFromUser(); /* Get user input */

		if (given_CommandFromUser == NULL)
		{ /* Check for end-of-file or error */
			if (isatty(STDIN_FILENO))
			{ /* Print a new line if in interactive mode */
				write(STDOUT_FILENO, "\n", 1);
			}
			return (condition);
		}
		index++; /* Increment command index */

		CMD = string_tokinizer(given_CommandFromUser); /* Tokenize the command */

		if (!CMD)
		{ /* Skip empty or invalid commands */
			continue;
		}

		if (ls_Bltn(CMD[0]))
		{ /* Handle built-in commands */
			bltn_Hand(CMD, argument_vector, &condition, index);
		}
		else
		{ /* Execute external commands */
			condition = exeCommand(CMD, argument_vector, index);
		}
	}
}
