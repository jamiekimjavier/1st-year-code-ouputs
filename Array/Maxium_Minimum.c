#include <stdio.h>

int main() {
    int numberOfElements;
    int maximum;
    int minimum;

    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);

    int elements[numberOfElements];

    printf("Enter the elements: \n");
    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &elements[i]);
    }

    for (int i = 0; i < numberOfElements; i++) {
        if (i == 0) {
            maximum = elements[i];
            minimum = elements[i];
        } else {
            if (elements[i] > maximum) {
                maximum = elements[i];
            }
            if (elements[i] < minimum) {
                minimum = elements[i];
            }
        }
    }

    printf("Maximum element: %d \n", maximum);
    printf("Minimum element: %d \n", minimum);

    return 0;
}