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
		exist(1);
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
