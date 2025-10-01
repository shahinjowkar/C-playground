#include <stdio.h>
#include <string.h>

void reader(char* line){
    char *dummy = line;
    char ch;
    int counter = 0;
    while((ch = getchar()) != '\n' && ch != EOF && ch != ' ' && counter++ < 21){
        *dummy++ = ch;
    }
    *dummy ='\0';
}

int
main(int argc, char *argv[]){
    char smallest[21] = "";
    char largest[21] = "";
    while(1){
        printf("Input Name: ");
        char animal[21];
        reader(animal);
        if(smallest[0] == '\0' || strcmp(smallest, animal) > 0){
            strcpy(smallest,animal);
        }
        if(largest[0] == '\0' || strcmp(largest,animal) < 0 ){
            strcpy(largest,animal);
        }
        if ( strlen(animal) == 4){
            break;
        }
    }
    printf("smalest animal is:%s \n", smallest);
    printf("largest animal is: %s \n", largest);

}
