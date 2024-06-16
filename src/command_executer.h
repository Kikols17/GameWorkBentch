#ifndef COMMAND_EXECUTER_H
#define COMMAND_EXECUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int help_command(char *response);
int version_command(char *response);
int authors_command(char *response);
int verbose_command(char *response);


#endif // COMMAND_EXECUTER_H