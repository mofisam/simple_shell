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
			if (tok[toklen + 1] == ':')
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

/**
 * _concat - Concatenates a user string with a PATH member string
 *           and a '/' character.
 * @tmp: Static array to store the concatenated string.
 * @samshell_args: Pointer to an array of user strings.
 * @tok: Pointer to a PATH token.
 *
 * Return: Returns a pointer to the concatenated string stored in 'tmp'.
 */
char *_concat(char *tmp, char **samshell_args, char *tok)
{
	int len = 0;

	/*Initialize the static array to store the concatenated string*/
	_memset(tmp, 0, 256);
	/*Calculate the length of concatenated string*/
	len = _strlen(tok) + _strlen(samshell_args[0]) + 2;
	/*Concatenate the PATH token, '/', and the user string*/
	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, samshell_args[0]);
	/*Ensure null-termination of the concatenated string*/
	tmp[len - 1] = '\0';
	/*Return a pointer to the concatenated string stored in 'tmp'*/
	return (tmp);
}
