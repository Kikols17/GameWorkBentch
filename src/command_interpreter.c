#ifndef COMMAND_INTERPRETER_C
#define COMMAND_INTERPRETER_C

#include "command_interpreter.h"
#include "utils.h"

extern bool verbose;


int interpret_commands(int argc, char *argv[], char *response) {
    /* Interpret the command and return the response
     * Returns:
     *      0: Success
     *      1: No arguments
     *      2: Invalid number of argument
     *      3: Invalid argument
     */
    if (argc==1) {
        // No arguments
        sprintf(response+strlen(response), "Welcome to \"%s\"\nUse \"-H\" commands!\n", argv[0]);
        return 1;
    }


    int ret = 0;
    char *command;
    //char *args[argc-2];     // the maximum number of arguments is argc - 1(name of process) -1(first command)

    for (int i=1; i<argc; i++) {
        command = argv[i];
        if (command[0]=='-'  &&  command[1]!='\0'  &&  command[2]=='\0') {
            // single character, starts with "-"
            if (command[1]=='H') {
                // Help command
                ret = help_command(response);
            
            } else if (command[1]=='V') {
                // Version command
                ret = version_command(response);
            
            } else if (command[1]=='A') {
                // Author command
                ret = authors_command(response);
            
            } else {
                // Invalid command
                sprintf(response+strlen(response), "Invalid command: %s\nALL COMMANDS HALTED", command);
                return 3;
            }


        } else if (command[0]=='-'  &&  command[1]=='-'  &&  command[2]!='\0') {
            // multiple characters, starts with "--"
            strtolower(command);        // when command is fully written, case is not important
            if (strcmp(command, "--help")==0) {
                // Help command
                ret = help_command(response);
            
            } else if ( strcmp(command, "--version")==0 ) {
                // Version command
                ret = version_command(response);
            
            } else if ( strcmp(command, "--author")==0 ) {
                // Author command
                ret = authors_command(response);
            
            }

        
        } else {
            sprintf(response+strlen(response), "Invalid argument: %s\n", command);
            return 3;
        }

        if (ret!=0) {
            return ret;
        }

    }

    return 0;
}

#endif // COMMAND_INTERPRETER_C