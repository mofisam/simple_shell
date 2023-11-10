#include "samshell_header.h"

/**
 * _env - Display SamShell Environment Variables
 *
 * This function is responsible for displaying the current set of
 * environment variables in the SamShell program. It iterates through
 * the array of environment variables & prints each one using the
 * _puts function.
 *
 * Return: Always returns 0 on success.
 */
int _env(void)
{
	int i;

	for (i = 0; samshell_env[i]; i++)
	{
		_puts(samshell_env[i]);
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

	for (i = 0; samshell_env[i]; i++)
	{
		result = _S_PATHstrcmp(name, samshell_env[i]);
		if (result == 0)
		{
			return (samshell_env[i]);
		}
	}
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

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
