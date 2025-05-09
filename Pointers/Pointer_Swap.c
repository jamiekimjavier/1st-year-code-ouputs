#include <stdio.h>

int main (void) {

    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("\nEnter second number: ");
    scanf("%d", &b);

    printf("\nBefore swapping: num 1 = %d, num 2 = %d", a,b);

    int *pA = &a;
    int *pB = &b;

    //swapping function

    int temp;
    temp = *pA;
    *pA = *pB;
    *pB = temp;

    printf("\nAfter swapping: num 1 = %d, num 2 = %d", *pA,*pB);

    return 0;
}