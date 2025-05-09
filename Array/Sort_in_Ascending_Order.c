#include <stdio.h>

int main() {
    int numberOfElements;

    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);

    int elements[numberOfElements];

    printf("Enter the elements: ");
    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &elements[i]);
    }

    for (int i = 0; i < numberOfElements - 1; i++) { 
        for (int j = 0; j < numberOfElements - i - 1; j++) {
            if (elements[j] > elements[j + 1]) {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");

    return 0;
}