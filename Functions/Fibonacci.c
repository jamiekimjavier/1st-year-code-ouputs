#include <stdio.h>

int fibonacci(int n);

int main() {
    int n = 10;

    printf("The 10th Fibonacci number is: %d\n", fibonacci(n));

    return 0;
}

int fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}
