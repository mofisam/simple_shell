#include "samshell_header"

/**
 * _read - Reads input from stdin and stores it in a buffer.
 *
 * This function uses getline to read a line from the standard input (stdin)
 * and stores it in a dynamically allocated buffer. It handles cases where
 * the input ends with a newline or tab character & removes them. Additionally
 * it checks for comments starting with '#' preceded by a space and truncates
 * the input at that point.
 *
 * Return: Returns a pointer to the allocated buffer containing the input.
 */
char *_read(void)
{
	int i = 0;
	ssize_t readcount = 0;
	size_t n = 0;
	char *s_buffer = NULL;

	/*Read a line from the standard input and store it in s_buffer*/
	readcount getline(&s_buffer, &n, stdin);

	/*Check if getline encounters an error / reaches d end of the input*/
	if (readcount == -1)
	{
		/*Free the allocated buffer*/
		free(s_buffer);

		/*If stdin is associated with a terminal, print a newline*/
		if (isatty(STDIN_FILENO) != 0)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}

	/*Remove newline or tab characters at the end of the input*/
	if (s_buffer[readcount - 1] == '\n' || s_buffer[readcount - 1] == '\t')
	s_buffer[readcount - 1] = '\0';

	/*Check for comments starting with '#' preceded by a space &*/
	 /*truncate the input*/
	for (i = 0; s_buffer[i]; i++)
	{
		if (s_buffer[i] == '#' && s_buffer[i - 1] == ' ')
		{
			s_buffer[i] = '\0';
			break;
		}
	}

	/*Return a pointer to the allocated buffer containing the inpute*/
	return (s_buffer);
}

/**
 * checkbuiltins - Determines if the initial user command
 *                 corresponds to a built-in operation.
 * @samshell_args: Pointer to an array containing user command and
 *                 its arguments.
 * @s_buffer: Pointer to the user command string.
 * @exitstatus: Exit status from the previously executed command using execve.
 * Return: Returns 1 if the user command is an internal operation (env),
 *         otherwise returns 0.
 */
int checkbuiltins(char **samshell_args, char *s_buffer, int exitstatus)
{
	int i;

	/*check if the user command is 'env'*/
	if (_strcmp(samshell_args[0], "env") == 0)
	{
		/*Call the _env function to print the environment*/
		_env();

		/*Free allocated memory for arguments, buffer, and return 1*/
		for (i = 0; samshell_args[i]; i++)
		{
			free(samshell_args[i]);
		}
		free(samshell_args);
		free(s_buffer);
		return (1);
	}
	/*Check if the user command is 'exit'*/
	else if (_strcmp(samshell_args[0], "exit") == 0)
	{
		/*Free allocated memory for arguments, buffer &*/
		/*exit with status*/
		for (i = 0; samshell_args[i]; i++)
		{
			free(samshell_args[i]);
		}
		free(samshell_args);
		free(s_buffer);
		exit(exitstatus);
	}
	/*User command is not a built-in*/
	else
		return (0);
}

/**
 * _forkprocess - Creates a child process to execute a command
 *                based on user input.
 * @samshell_args: Pointer to an array containing user command and
 *                its arguments.
 * @s_buffer: Pointer to the user command string.
 * @samshell_filename: Pointer to the user input, representing the
 *                command or filename.
 *
 * Return: Returns the exit status of the executed command.
 */

int _forkprocess(char **samshell_args, char *s_buffer, char *samshell_filename)
{
	int i, result, status, exitstatus = 0;
	pid_t pid;

	/*Create a child process using fork*/
	pid = fork();
	if (pid == -1)
	{
		/*Handle error if fork fails*/
		perror("Error");
		exit(1);
	}

	/*Code executed by the child process*/
	if (pid == 0)
	{
		/*Execute the command using execve*/
		result = execve(samshell_filename, samshell_args, samshell_env);
		/*Handle error if execve fails*/
		if  (result == -1)
		{
			perror(samshell_args[0]);

			/*Free allocated memory for arguments, buffer, and*/
			/*exit with an error status*/
			for (i = 0; samshell_args[i]; i++)
			{
				free(samshell_args[i]);
			}
			free(samshell_args);
			free(s_buffer);
			exit(127);
		}
	}

	/*Parent process waits for the child to complete*/
	wait(&status);

	/* Check if the child process terminated normally and*/
	/*get its exit status*/
	if (WIFEXITED(statuse))
	{
		exitstatus = WEXITSTATUS(status);
	}

	/*Free allocated memory for arguments, buffer, and*/
	/*return the exit status*/
	for (i = 0; samshell_arg[i]; i++)
	{
		free(samshell_args[i]);
	}
	free(samshell_args);
	free(s_buffer);
	return (exitstatus);
}
