#include <stdio.h>

int main() {
    int numbers[] = {1, -4, 20, 7, 80, 34, 100};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int largest = numbers[0];
    int smallest = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    printf("Number elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}
