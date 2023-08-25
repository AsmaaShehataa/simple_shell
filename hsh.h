#ifndef HSH_H
#define HSH_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

extern char **environ;
extern int EXIT_STATUS;

/**
 * struct aliases - struct aliases
 * @name: alias name
 * @value: alias value
 */
typedef struct aliases
{
	char *name;
	char *value;
} aliases;
int split_line(char *, char *, aliases *, int *);
char **_strtok(char *, char *);
int _getline(char **);
int _read(char **, char **);
int exec_cmd(char **, char *, char *);
void get_cmds(char ***, char *);
void _free_buffer(char **);
void *_calloc_buffer(unsigned int, unsigned int);
int _fork_process(char *, char **);
int args_count(char **);
char *check_validation(char *, char *, char **);
char *check_ops(char **);
char *_getenv(char *);
int _get_alias(aliases *, char *, int);
int echo_handeler(char **);
int error_handeling(char *, char **, char *, int);

/* printing functions */
int to_string(int, unsigned int);
int print_string(int, char *);
int cmd_selector(const char *, char **, char *,
		aliases *, int *, char **, char *);
int switch_dir(int, char **, char *, aliases *, int *, char **, char *);
int exit_function(int, char **, char *, aliases *, int *, char **, char *);
int export(int, char **, char *, aliases *, int *, char **, char *);
int unset(int, char **, char *, aliases *, int *, char **, char *);
int env_handler(int, char **, char *, aliases *, int *, char **, char *);
int _alias_handeler(int, char **, char *, aliases *, int *, char **, char *);

/* custom string manipulation functions */
char **_strtok(char *, char *);
char *_strpbrk(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
void rm(char **);
size_t _strlen(char *);
int _strcmp(const char *, char *);
int _strncmp(const char *, char *, int);
char *_strstr(char *, char *);
char *_memcpy(char *, char *, unsigned int);
void substring_tok(char *, char *, char *);
int _atoi(char *);


/* command execution list*/
/**
 * struct cmd_executer - structure
 * @cmd: the command
 * @exec_func: the function
 */
typedef struct cmd_executer
{
	char *cmd;
	int (*exec_func)(int, char **, char *, aliases *, int *, char **, char *);
} cmd_executer;
#endif
