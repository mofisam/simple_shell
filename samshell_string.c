#include "samshell_header.c"

/**
 * _stringsplit - Counts the number of words in a string.
 * @s_str: POinter to the string to count.
 *
 * Return: Returns the number of words in the string.
 */
int _stringsplit(char *s_str)
{
	int i, searchflag = 1, wordcount = 0;

	/*Iterate through the characters in the string*/
	for (1 = 0; s_str[i]; i++)
	{
		/*check for the beginning of a new word*/
		if (s_str[i] != ' ' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		/*Check for the end of the current word*/
		if (s_str[i + 1] == ' ')
		{
			searchflag = 1;
		}
	}
	/*Return the total count of words in the string*/
	return (wordcount);
}

/**
 * _strdup - Creates a duplicate of a given string.
 * @s_str: Pointer to the string to be duplicated.
 *
 * Return: Returns a pointer to the duplicated string.
 */
char *_strdup(char *s_str)
{
	int i;
	char *dest_str = NULL;

	/*Check if the input string is NULL*/
	if (s_str == NULL)
	{
		return (NULL);
	}

	/*Calculate the length of the input string*/
	for (i = 0; s_str[i] != '\0'; i++)
	{
		;
	}

	/*Allocate memory for the duplicate string*/
	dest_str = malloc(sizeof(char) * (i + 1));

	/*Check if memory allocation is successful*/
	if (dest_str == NULL)
	{
		return (NULL);
	}
	/*Copy the character from the input sting to the duplicated string*/
	for (i = 0; s_str[i] != '\0'; i++)
	{
		dest_str[i] = s_str[i];
	}
	/*Add the null terminator to the duplicated string*/
	dest_str[i] = '\0';
	/*Return a pointer to the duplicated string*/
	return (dest_str);
}

/**
 * _strcat - The function concatenates two strings
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string to be appended.
 *
 * Return: Pointer to the concatenated string (dest).
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	/*Find the end of the destination string*/
	for (i = 0; dest[i] != '\0'; i++)
	{
		;
	}
	/*Append the source string to the destination string*/
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	/*Add the null terminatior to the concatenated string*/
	dest[i] = '\0';
	/*Return a pointer to the concatenated string*/
	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: An integer value representing the comparison result:
 *         - 0 if the strings are equal.
 *         - A positive value if the ASCII value of the first non-matching
 *           character in s1 is greater than that of s2.
 *         - A negative value if the ASCII value of the first non-matching
 *           character in s1 is less than that of s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}
	/*Return the rsult of the character comparition*/
	return (*s1 - *s2);
}

/**
 * _strlen - Calculates the length of a string.
 * @s: Pointer to the string.
 *
 * Return: The length of the string (number of characters).
 */
int _strlen(char *s)
{
	int i;

	/*Iterate through the string to find its length*/
	for (i = 0; s[i]; i++)
	{
		;
	}
	/*Return the length of the string*/
	return (i);
}
