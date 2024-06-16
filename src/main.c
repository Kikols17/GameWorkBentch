#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "command_interpreter.h"
#include "command_executer.h"

int main(int argc, char *argv[]) {
    if (argc==1) {
        printf("Welcome to \"%s\"\nUse \"-h\" commands!\n", argv[0]);
        return 1;
    }
    return 0;
}