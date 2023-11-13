#include "samshell_header.h"
/**
 * _samshell_fullpath - Locates the full path of the executable for execve.
 * @samshell_args: Pointer to an array containing user command & its arguments.
 * @PATH: Pointer to the PATH environment variable.
 * @copy: Copy of the PATH string used for tokenization.
 * Return: Returns a pointer to the full path of the executable for execve.
 *
 * This function iterates through directories specified in the PATH environment
 * variable and constructs potential full paths by concatenating them with the
 * user command. It checks if each potential full path corresponds to a valid
 * executable. If found, it returns the full path; otherwise, it defaults to
 * using the user command as the executable.
 */
char *_samshell_fullpath(char **samshell_args, char *PATH, char *copy)
{
	char *samshell_filename = NULL, *tok = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, toklen = 0, z = 0;
	struct stat h;
	/*Create a copy of the PATH string for tokenization*/
	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _samshell_splitPATH(copy); /*Count the number of directories*/
	tok = strtok(copy, ": ="); /*Tokenize the PART string*/
	/*Iterate through each directory in the PATH*/
	while (tok != NULL)
	{
		concatstr = _concat(tmp, samshell_args, tok); /*Concatenate the directory*/
		if (stat(concatstr, &h) == 0)
		{
			samshell_filename = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _strlen(tok);
			/*Check if d user command is a valid executable in CD*/
			if (tok[token + 1] == ':')
			{
				if (stat(samshell_args[0], &h) == 0)
				{
					samshell_filename = samshell_args[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++; /*Move to the next directory in the PATH*/
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		samshell_filename = samshell_args[0];
	free(copy);/*Free allocated memory for the copied PATH*/
	return (samshell_filename);
}
