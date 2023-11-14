#include "samshell_header.h"

/**
 * main - Entry point for the samshell program.
 *
 * This function initializes the samshell by setting up necessary variables
 * and signals. It then enters a continuous loop to prompt the user for input,
 * read the input, tokenize it, identify the full path of the executable,
 * check for built-in commands and fork a process to execute external commands.
 * The loop continues until the user exits the shell.
 *
 * Return: Returns 0 on successful execution.
 */
int main(void)
{
	char *samshell_filename = NULL, *copy = NULL, *s_buffer = NULL, *PATH = NULL;
	char **samshell_args = NULL;
	int exitstatus = 0;

	/*Ignore the SIGINT signal to prevent termination on Ctrl+C*/
	signal(SIGINT, SIG_IGN);
	/*Retrieve the PATH variable from the environment*/
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
	/*Main shell execution loop*/
	while (1)
	{
		samshell_args = NULL;
		/*Display the shell prompt and read user input*/
		samshell_prompt();
		s_buffer = _read();
		/*Check if the input is not empty*/
		if (*s_buffer != '\0')
		{
			samshell_args = tokenize(s_buffer); /*Tokenize the user input*/
			if (samshell_args == NULL)
			{
				free(s_buffer);
				continue;
			}
			/*find the full path of the executable*/
			samshell_filename = _samshell_fullpath(samshell_args, PATH, COPY);
			/*Check for and execute built-in commands*/
			if (checkbuiltins(samshell_args, s_buffer, exitstatus) != 0)
				continue;
			/*Fork a process to execute external commands*/
			exitstatus = _forkprocess(samshell_args, s_buffer, samshell_filename);
		}
		else
		{
			free(s_buffer);
		}
	}
	return (0);
}
