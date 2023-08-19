#ifndef HSH_H
#define HSH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

char **arg_process(char *user_input);
void exec_command(char **arr_holder, char **env, char *user_input);
int arg_arr_lenth(char *user_input);
int print_env(char **env, char *user_input);
int  __exit(char *user_input);

#endif
