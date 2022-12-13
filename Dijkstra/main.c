#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "functions.c"

#define TRUE 1
#define FALSE 0

typedef int bool;

int main(int arg, char *argv[]){

    int output = 0, inpt = 0, vertInicial = 0, vertFinal = 0;

    bool soluc = FALSE;

    for (int i = 0; i < arg; i++)
    {
        if(strcmp(argv[i], "-h") == 0){
            help();
            return 0;
        }
        else if(strcmp(argv[i], "-o") == 0){
            output = i + 1;
        }
        else if(strcmp(argv[i], "-f") == 0){
            inpt = i + 1;
        }
        else if(strcmp(argv[i], "-s") == 0){
            soluc = TRUE;
        }
        else if(strcmp(argv[i], "-i") == 0){
            vertInicial = argv[i+1];
        }
        else if(strcmp(argv[i], "-l") == 0){
            vertFinal = argv[i+1];
        }
    }

    // --- ENTRADA ---



    // --- SAÍDA ---
    FILE *out = fopen(argv[output], "w");
    fprintf(out, "okei");
    fclose(out);
    
    return 0;
}