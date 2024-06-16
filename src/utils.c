#ifndef UTILS_C
#define UTILS_C

#include "utils.h"

void strtolower(char *str) {
    for (int i=0; str[i]!='\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}


#endif // UTILS_C