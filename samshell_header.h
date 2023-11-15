#ifndef HEADER_FILE
#define HEADER_FILE

/**
 * HEADER FILE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

/*Declare an external variable for the shell environment*/
extern char **environ;

/*Function related to the PATH variable an shell ececution*/
int samshell_prompt(void);
char *_read(void);
int checkbuiltins(char **samshell_args, char *s_buffer, int exitstatus);
char *_samshell_fullpath(char **samshell_args, char *PATH, char *copy);
int _forkprocess(char **samshell_args, char *s_buffer, char *samshell_filename);

char *_strdup(char *s_str);
char *_strcat(char *dest, char *src);
int _stringsplit(char *s_str);
int _strcmp(const char *s1, const char *s2);
int _strlen(char *s);

char *_getenv(const char *name);
int samshell_env(void);
void _puts(char *s_str);
char *_memset(char *s, char b, unsigned int n);
int _putchar(char c);

int _samshell_splitPATH(char *s_str);
char **tokenize(char *s_buffer);
int _S_PATHstrcmp(const char *s1, const char *s2);
char *_concat(char *tmp, char **samshell_args, char *tok);

#endif
