#include <stdio.h>
#include <stdlib.h>





void processInput(const char *fraction, int *numerator, int *denominator){
    
    sscanf(fraction, "%d / %d", numerator,denominator);
    for(int i = *numerator; i>0;i--){
        if(*denominator%i == 0 && *numerator%i == 0){
            *denominator = *denominator/i;
            *numerator = *numerator/i;
            break;
        }
    }
   
}


int
main(int argc, char *argv[]){
    char fraction[50];
    int numerator;
    int denominator;

    printf("enter the fraction(format:num1/num2):  ");
    scanf("%s", fraction);
    processInput(fraction, &numerator, &denominator);
    printf("%d/%d\n",numerator,denominator);
}