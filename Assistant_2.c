#include "simple_shell.h"

/**
 * _strrev - reverses a string
 * @string: string to be reversed
 * @len: length of the string
 * Return: void
 *
 * Description: This function reverses the given string in place.
 */
void _strrev(char *string, int len)
{ /* Swap characters from both ends of the string until the middle is reached*/
	char temporary;
	int begin = 0;
	int terminate = len - 1;

	while (begin < terminate)
	{ /* Swap characters */
		temporary = string[begin];
		string[begin] = string[terminate];
		string[terminate] = temporary;
		/* Move indices towards the middle */
		begin++;
		terminate--;
	}
}

/**
 * stringtointeger - convert string to integer
 * @string: the string to convert
 * Return: the integer
 *
 * Description: This function converts a string representing an integer
 * into an actual integer value.
 */
int stringtointeger(char *string)
{ /* Convert each character to its numeric value and construct the integer */
	int index, number = 0;

	for (index = 0; string[index]; index++)
	{ /* Multiply current number by 10 and add the new digit */
		number *= 10;
		number += (string[index] - '0');
	}

	return (number);
}

/**
 * checkifthegivennumberispostive - check if the given number is positive
 * @string: the string to check
 * Return: 1 if the number is positive, 0 if not
 *
 * Description: This function checks if the given string represents a positive
 * integer by verifying that all characters are numeric.
 */
int checkifthegivennumberispostive(char *string)
{
	int index;

	if (!string)
	{ /* Return 0 if the string is NULL */
		return (0);
	}

	for (index = 0; string[index]; index++)
	{ /* Check if each character is a numeric digit */
		if (string[index] < '0' || string[index] > '9')
		{
			return (0);
		}
	}

	return (1);
}
