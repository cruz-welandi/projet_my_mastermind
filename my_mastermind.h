#ifndef MY_MASTERMIND_H
#define MY_MASTERMIND_H
#include <string.h>
#include <stdlib.h>


#define CODE_LENGTH 4


char* generate_secret_code() {
    char* code = (char*)malloc(CODE_LENGTH + 1);
    const char pieces[] = "012345678";

    for (int i = 0; i < CODE_LENGTH; i++) {
        int random_index = rand() % strlen(pieces);
        code[i] = pieces[random_index];
    }

    code[CODE_LENGTH] = '\0';
    return code;
}


#endif