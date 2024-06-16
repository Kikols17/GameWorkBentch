#ifndef COMMAND_EXECUTER_C
#define COMMAND_EXECUTER_C

#include "command_executer.h"

extern bool verbose;

int help_command(char *response) {
                sprintf(response+strlen(response), "HELP! List of commands:\n"
                                                   "\t-H\t--help:\t\tDisplay help\n"
                                                   "\t-V\t--version:\t\tDisplay version\n"
                                                   "\t-A\t--author:\t\tDisplay author\n");
    return 0;
}

int version_command(char *response) {
    sprintf(response+strlen(response), "Version WORK-IN-PROGRESS\n");
    return 0;
}

int authors_command(char *response) {
    sprintf(response+strlen(response), "Authors:\n"
                                       "\tKikols\thttps://github.com/Kikols17\n");
    return 0;
}

int verbose_command(char *response) {
    verbose = true;
    sprintf(response+strlen(response), "Verbose mode enabled! (\"[...]my hyper-intelligent and verbose dog\")\n");
    return 0;
}

#endif // COMMAND_EXECUTER_C