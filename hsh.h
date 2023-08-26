#ifndef HSH_H
#define HSH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
extern char **environ;

struct hsh_status
{
	char *name;
	int cmd_count;
	int status;
};
typedef struct hsh_status hsh_t;
extern hsh_t prog;

char **arg_process(char *user_input, char *delim);
void exec_command(char **arr_holder, char *av);
int print_env(char **arr_holder);
int  b_exit(char **arr_holder, char *user_input);
char **get_path_arr(const char *path_str, char **env);
char *path_value(char *path_str);
int check_command(char *executable);
int check_builtin(char **arr_holder, char *user_input);
int check_slash(char *executable_holder);
int c_availability(char *command);
void prompt_holder(char *user_input, char *av);
void print_string(char *string);
char *modify_buffer(char *s);
#endif
