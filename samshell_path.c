#include "samshell_header.h"

/**
 * _samshell_fullpath - Locates the full path of the executable for execve.
 * @samshell_args: Pointer to an array containing user command and its arguments.
 * @PATH: Pointer to the PATH environment variable.
 * @copy: Copy of the PATH string used for tokenization.
 *
 * Return: Returns a pointer to the full path of the executable for execve.
 *
 * This function iterates through directories specified in the PATH environment
 * variable and constructs potential full paths by concatenating them with the
 * user command. It checks if each potential full path corresponds to a valid
 * executable. If found, it returns the full path; otherwise, it defaults to
 * using the user command as the executable.
 */

