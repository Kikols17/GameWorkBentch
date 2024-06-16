#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "command_interpreter.h"
#include "command_executer.h"


bool verbose = false;


// Main function
int main(int argc, char *argv[]) {
    // Interpret arguments
    char response[1024];
    response[0] = '\0';

    
    // Interpret the command and print the response
    int intr_ret = interpret_command(argc, argv, response);
    printf("%s", response);

    return intr_ret;
}