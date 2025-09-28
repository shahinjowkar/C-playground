#include <stdio.h>

#define MAX_LEN 100   

void subscriptionMethod(char result1[],char input[], int size){
    int j = 0;
    for(int i = size - 1; i >= 0 ; i--){
        result1[j] = input[i];
        j++;
    }

}
void pointerMethod(char *result1, char *input, int size){
    for(char *i = input + size - 1; i >= input ; i--){
        *(result1++) =  *i; 
    }
}

void inPlace(char *result,int size){
    char *left = result;
    char *right = result + size - 1;
    while(left < right){
        char dummy = *left;
        *left++ = *right;
        *right-- = dummy;
    }
}

void display(char *result,int size){
    for(int i = 0; i <= size ;i++){
        putchar(result[i]);
    }
    printf("\n");
}


int 
main(void) {
    char input[MAX_LEN] = {0};
    printf("input string:");
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n' && ch != EOF){
        input[i++] = ch;
    }
    char result1[i];
    char result2[i];   
    subscriptionMethod(result1, input,i);
    pointerMethod(result2, input, i);
    inPlace(input, i);
    printf("subscription method\n");
    display(result1,i);
    printf("pointer method\n");
    display(result2,i);
    printf("In place variation\n");
    display(input, i);

    
}