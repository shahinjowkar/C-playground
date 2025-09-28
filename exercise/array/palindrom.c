#include <stdio.h>
#include <stdbool.h>







bool isPalindromS(char input[], int size){
    int left = 0;
    int right = size - 1;
    while(left < right){
        if(input[left++] != input[right--]){
            return false;
        }
    }
    return true;

}
bool isPalindromP(char *input, int size){
    char *left = input;
    char *right = input + size - 1;
    while(left < right){
        if(*left++ != *right--){
            return false;
        }
    }
    return true;
}

void display(char *res,int size){
    for(int i = 0; i< size; i++){
        putchar(res[i]);
    }
}

int
main(int argc, char *argv[]){
    char input[256];
    char ch;
    int size = 0;
    printf("inpu value:");
    while((ch = getchar()) != '\n' && ch !=EOF){
        input[size++] = ch;
    }
    printf("yout value\n:");
    display(input, size);
    printf("this is pointer one\n:");
    printf("%d\n",isPalindromP(input,size));
    printf("this is subscription one\n:");
    printf("%d\n",isPalindromS(input,size));


}