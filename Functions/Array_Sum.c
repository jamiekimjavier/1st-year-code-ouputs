#include <stdio.h>

int sumArray(int array[], int size);

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    for (int i = 0; i < size; i++) {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Sum: %d", sumArray(array, size));

    return 0;
}

int sumArray(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}
