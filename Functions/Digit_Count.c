#include <stdio.h>
#include <math.h>

int countDigits(int num);

int main(){
    int num;

    printf("Enter the number of which the digits are to be counted: \n");
    scanf("%d", &num);

    printf("Digit count: %d", countDigits(num));


    return 0;
}

int countDigits(int num){
    return (int)log10(num) + 1;
}