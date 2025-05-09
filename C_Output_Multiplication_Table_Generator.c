#include <stdio.h>

int main() {

    int number;
    int limit;

    do {
        printf("Enter a non-negative integer: ");
        scanf("%d", &number);
        if (number < 0) {
            printf("Please enter positive integers only.\n");
        }
    } while (number < 0);

        do {
            printf("Up to what number should the table go?: ");
            scanf("%d", &limit);
            if (limit < 0) {
                printf("Please enter positive integers only.\n");
            }
        } while (limit < 0);

        for (int i = 1; i <= limit; ++i) {
            printf("%d * %d = %d \n", number, i, number * i);
        }

    return 0;
}