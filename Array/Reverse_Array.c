#include <stdio.h>

int main() {
    int numberOfElements;

    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);

    int elements[numberOfElements];

    printf("Enter the elements: \n");

    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &elements[i]);
    }

    printf("Reversed array:");
    for (int i = numberOfElements - 1; i >= 0; i--) {
    printf("%d ", elements[i]);
    }

    return 0;
}