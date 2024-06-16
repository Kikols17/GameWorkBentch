#ifndef COMMAND_EXECUTER_C
#define COMMAND_EXECUTER_C

#include "command_executer.h"

int help_command(char *response) {
    sprintf(response+strlen(response), "HELP! List of commands\n");
    return 0;
}

#endif // COMMAND_EXECUTER_C