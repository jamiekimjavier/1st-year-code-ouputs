#include <stdio.h>

int fibonacci(int n);

int main (void) {
    int num = 10;

    printf("Fibonacci up to %d terms: \n", num);

    for(int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }


    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}