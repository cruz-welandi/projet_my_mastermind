#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "my_mastermind.h"

#define CODE_LENGTH 4



int main(int arg, char** argv) {
    srand(time(NULL));
    int max_attemps = 10;
    char code_entrer[CODE_LENGTH+1];
    char* code_secret = NULL;

    for(int i=1; i<arg; i++){
        if(strcmp(argv[i], "-c") == 0 && i+1 < arg){
            code_secret = argv[i+i];
        }
        else if(strcmp(argv[i], "-t") == 0 && i+1 < arg){
            max_attemps = atoi(argv[i+1]);
        }
    }

    if(code_secret == NULL){
        code_secret= generate_secret_code();
    }

    printf("will you find the secret code?\nPlease enter a valid guess\n---\n");


    for(int round = 0; round < max_attemps; round++){
        printf("Round %d\n", round);
        printf(">");
        scanf("%s", code_entrer);

        int nbr =0;
        for(int j=0; j<4; j++){
            if(isalpha(code_entrer[j])) {
                nbr++;
            }
        }
        if(strlen(code_entrer) != CODE_LENGTH || nbr >0) {
            printf("Wrong input!\n");
            continue;
        }

        int  well_placed = 0;
        int misplaced =0;
    //verification des chriffres bien placés et mal placés
    for(int i=0; i<CODE_LENGTH; i++) {
            if(code_secret[i] == code_entrer[i]){
                well_placed++;
            }
            else if(strchr(code_secret,code_entrer[i]) != 0){
                misplaced++;
            }
        }
    if(well_placed == CODE_LENGTH) {
        printf("Congratz! You did it!\n");
        break;
    }
    else{
        printf("Well placed pieces: %d\nMisplaced pieces: %d\n---\n",well_placed, misplaced);
    }
}
    free(code_secret);
    return 0;
}