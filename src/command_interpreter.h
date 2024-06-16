#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "command_executer.h"


int interpret_commands(int argc, char *argv[], char *response);


#endif // COMMAND_INTERPRETER_H