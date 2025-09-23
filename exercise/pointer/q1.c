/**
Modify Programming Project 7 from Chapter 2 so that it includes the following function:
void pay_amount(int dollars, int *twenties, int *tens,
int *fives, int *ones);
The function determines the smallest number of $20, $10, $5, and $1 bills necessary to pay
the amount represented by the dollars parameter. The twenties parameter points to a
variable in which the function will store the number of $20 bills required. The tens,
fives, and ones parameters are similar.
 */


#include <string.h>
#include <stdio.h>


void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
    int amount[]= {20, 10, 5, 1};
    int *change[]= {twenties, tens, fives, ones};
    int size = sizeof(amount)/sizeof(amount[0]);
    for(int i=0; i<size; i++){
        *change[i] = dollars/amount[i];
        dollars = dollars%amount[i];
    }
}

int
main(int argc, char *argv[]){
    while(1){       
        int dollars;
        int twenties, tens, fives, ones;
        printf("Enter amount: ");
        scanf("%d", &dollars);
        pay_amount(dollars, &twenties, &tens, &fives, &ones);
        printf("twenties:%d -- tens:%d -- fives:%d -- ones:%d\n", twenties, tens, fives, ones);
    }
}