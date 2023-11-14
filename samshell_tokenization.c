#include "samshell_header.h"

/**
 * tokenize - Creates an array of tokens based on the user input string.
 * @s_buffer: Pointer to the user input string.
 *
 * Return: Returns a pointer to an array of strings representing the tokens.
 */
char **tokenize(char *s_buffer)
{
	char *token = NULL;
	int i = 0, wordcount = 0;
	char *s_delimiter = " \n";
	char **samshell_args = NULL;

	/*Count the number of words in the user input string*/
	wordcount = _stringsplit(s_buffer);
	/*Check if there are no words*/
	if (!wordcount)
	{
		return (NULL);
	}
	/*Allocate memory for the array of strings (tokens)*/
	samshell_args = malloc((wordcount + 1) * sizeof(char *));
	if (samshell_args == NULL)
	{
		exit(1);
	}
	/*Tokenize the user input string using the specified delimiters*/
	token = strtok(s_buffer, s_delimiter);
	while (token != NULL)
	{
		/*Duplicate each token and store it in the array*/
		samshell_args[i] = _strdup(token);
		token = strtok(NULL, s_delimiter);
		i++;
	}
	/*Add a Null pointer at the end to signify the end of the array*/
	samshell_args[i] = NULL;
	/*Return a pointer to the array of tokens*/
	return (samshell_args);
}

/**
 * _samshell_splitPATH - Counts the number of PATH members.
 * @s_str: Pointer to the string containing the PATH variable.
 *
 * Return: Returns the number of directories in the PATH.
 */
int _samshell_splitPATH(char *s_str)
{
	int i, wordcount = 0, searchflag = 1;

	/*Iterate through the characters inthe PATH string*/
	for (i = 0; s_str[i]; i++)
	{
		/*Check for the beginning of a new PATH member*/
		if (s_str[i] != ':' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		/*Check for consecutive colons, indicating empty PATH member*/
		if (s_str[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	/*Return the total count of PATH members*/
	return (wordcount);
}

/**
 * _S_PATHstrcmp - Compares the PATH string with a samshell_env string
 *              to find the PATH value.
 * @s1: Pointer to the PATH string.
 * @s2: Pointer to the samshell_env string containing the actual value.
 *
 * Return: Returns 0 on success, indicating a match between
 *         PATH and samshell_env.
 */
int _S_PATHstrcmp(const char *s1, const char *s2)
{
	int i;

	/*Iterate through the characters until reaching the*/
	/*'=' sign in the samshell_env string*/
	for (i = 0; s2[i] != '='; i++)
	{
		/*Compare the characters of PATH with the*/
		/*corresponding characters in samshell_env*/
		if (s1[i] != s2[i])
		{
			return (-1);
		}
	}
	/*Return 0 on success, indicating a match*/
	return (0);
}
