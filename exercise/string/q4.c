#include <stdio.h>
int
main(int argc, char *argv[]){
    int size = argc;
    char *result[size - 1];
    char **p = result;
    for(int i = size - 1 ; i > 0 ; i--){
        *p++ = argv[i];
    }
    for(int j = 0 ; j<size-1; j++){
        printf("%s ", result[j]);
    }
}