#include <stdio.h>

int average(int a, int b, int c);

int main(){
    int a, b, c;

    printf("Enter three numbers to get the average.\n");
    scanf("%d\n", &a);
    scanf("%d\n", &b);
    scanf("%d", &c);

    printf("%d", average(a, b, c));

    return 0;
}

int average(int a, int b, int c){
    return (a + b + c) / 3;
}