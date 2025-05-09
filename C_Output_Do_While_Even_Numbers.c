#include <stdio.h>

int main() {
    int number;

    do {
        printf("Enter an even number: ");
        scanf("%d", &number);

    } while (number % 2 != 0);

    printf("You entered: %d.\n", number);

    return 0;
}
