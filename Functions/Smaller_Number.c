#include <stdio.h>

int findMinimum(int a, int b);

int main(){
    int a, b;

    printf("Enter two numbers to find the smaller one.\n");
    scanf("%d\n", &a);
    scanf("%d", &b);

    printf("%d", findMinimum(a, b));

    return 0;
}

int findMinimum(int a, int b){
    return (a < b)? a : b;
}