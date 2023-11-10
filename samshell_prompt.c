#include "samshell_header.h"

/**
 * samshell_prompt - Write a prompt to the standard output.
 *
 * This function displays the SamShell command prompt, represent by the
 * "$ " string, on the standard output. It checks if the standard input is
 * associated with a terminal before printing the prompt.
 *
 * Return: Always  returns 0 on success.
 */
int samshell_prompt(void)
{
	char *samshell_prompt = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, samshell_prompt, 2);
		if (writecount == -1)
		{
			exit(0);
		}
	}

	return (0);
}
