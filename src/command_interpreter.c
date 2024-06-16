#ifndef COMMAND_INTERPRETER_C
#define COMMAND_INTERPRETER_C

#include "command_interpreter.h"

int interpret_command(int argc, char *argv[]) {
    if (argc==1) {
        printf("Welcome to \"%s\"\nUse \"-h\" commands!\n", argv[0]);
        return 1;
    }
    return 0;
}

#endif // COMMAND_INTERPRETER_C