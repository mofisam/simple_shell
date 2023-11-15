#include "samshell_header.h"

/**
 * samshell_env - Display SamShell Environment Variables
 *
 * This function is responsible for displaying the current set of
 * environment variables in the SamShell program. It iterates through
 * the array of environment variables & prints each one using the
 * _puts function.
 *
 * Return: Always returns 0 on success.
 */
int samshell_env(void)
{
	int i;

	/*Iterate through environmental variables*/
	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
	}
	return (0);
}

/**
 * _putchar -Print a single character to the standard output.
 * @c: The character t be printed.
 *
 * Return: Returns the return value of the write system call, which
 * represents the number of characters written (1 in this case).
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print a string to the standard output follwed by a new line.
 * @s_str: The string to be printed.
 */
void _puts(char *s_str)
{
	int c;

	for (c = 0; s_str[c] != '0'; c++)
	{
		_putchar(s_str[c]);
	}
	_putchar('\n');
}

/**
 * _getenv - Retrieves the value associated with a specific
 *           environment variable.
 * @name: Pointer to the environment variable name, such as "PATH".
 *
 * Return: Returns a pointer to the value of d specified environment variable
 *         or NULL if the variable is not found.
 */
char *_getenv(const char *name)
{
	int i;
	int result;

	/*Iterate through the environment variables*/
	for (i = 0; environ[i]; i++)
	{
		/*Compare the names using a custom comparison function*/
		result = _S_PATHstrcmp(name, environ[i]);
		/*If a match is found return the corresponding environment variable*/
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	/*Return Null if no match is found*/
	return (NULL);
}

/**
 * _memset - Fills a block of memory with a specified byte.
 * @s: Pointer to the memory block to fill.
 * @b: The constant byte to fill the memory block with.
 * @n: The number of bytes to fill.
 *
 * Return: Returns a pointer to the memory block.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	/*Check for NULL pointer*/
	if (s == NULL)
	{
		return (NULL);
	}

	/*Fill the memory area with the specified byte value*/
	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	/*Return a pointer to the filled memory area*/
	return (s);
}
