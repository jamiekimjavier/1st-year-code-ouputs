#include <stdio.h>

int Sum(int a, int b);

int main(){
    int a, b;

    printf("Enter two numbers to get the sum.\n");
    scanf("%d\n", &a);
    scanf("%d", &b);

    printf("%d", Sum(a, b));

    return 0;
}

int Sum(int a, int b){
    return a + b;
}