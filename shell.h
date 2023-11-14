#ifndef _SHELL_H_
#define _SHELL_H_
#define MAX_LINE_LENGHT 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <signal.h>
/**
 * struct alias_node - a structure to create
 * a node for tempory alias
 * @alias_name: to create tempory name for the node
 * @alias_args: to create tempory arguments name for the node
 * @next: pointer to the next node
 */
typedef struct alias_node
{
	char *alias_name;
	char *alias_args;
	struct alias_node *next;
} a_node;
/**
 * struct alias - structure to store the alias node
 * @alias_name: holds the name to be stored
 * @alias_args: holds the arguments
 */
typedef struct alias
{
	char *alias_name;
	char *alias_args;
} alias;

extern char **environ;

void free_all_main(char **commands, char *input_alias, char **input);
void execute_command(char *program_path, char **program_arg);
a_node *add_node(a_node **head, char *name, char *args);
void free_all(char *path, char *str, char **commands);
char **get_arguments(char *str, char *delimiter);
int check_continue(char *str, char **commands);
void check_null(char **commands, char *error);
void int_to_string(char *buffer, int num);
void execute_file(char *file_name);
void free_me(char **ptr);
void shell_prompt(void);
char *check_env_path();
char **read_line();

/*Utils*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *concatenate_format(char *str1, char *str2);
char *_strtok(char *str, char *delim);
char *_strstr(char *haystack, char *needle);
char *_strpbrk(char *s, char *accept);
int search_char(char c, char *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
void print_alias(alias *tmp);
char *_strdup(char *str);
int _strlen(char *s);
int _atoi(char *s);


/*builtins*/
void handle_signals_C(int signal_num);
int check_builtins(char **commands);
int special_case_semi(char *str);
int check_special(char *input);
char check_alias(char *input);
char **get_alaises(char *str);
int cd(char  *program_path);
int exit_shell(int status);
int unset_env(char **args);
int set_env(char **args);
int print_env(void);

#endif
