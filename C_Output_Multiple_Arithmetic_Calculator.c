#include <stdio.h>

int main(void) {
    int a;
    int b;

    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter another number: ");
    scanf("%d", &b);



    printf("This is the product of your numbers: %.2f \n", (float)a*b);
    printf("This the sum of your numbers: %.2f \n", (float)a + b);
    printf("This is the difference of your numbers: %.2f \n", (float)a - b);
    printf("This is the quotient of your numbers: %.2f \n", (float)a / b);

    return 0;
}