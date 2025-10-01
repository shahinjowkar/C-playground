#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
main(int argc, char *argv[]){
    int res = 0;
    if(argc < 3){
        printf("atleast two argment needed\n");
        exit(1);
    }
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i],"0") != 0 && atoi(argv[i]) == 0){
            printf("only digits are acceptable as an argument\n");
            exit(1);
        }
        res = res + atoi(argv[i]);
        
    }
    printf("%d\n" ,res);
}