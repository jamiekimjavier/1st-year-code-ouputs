#include <stdio.h>

int main() {
    int numberOfElements;
    int search;

    printf("Enter number of elements: ");
    scanf("%d", &numberOfElements);

    int elements[numberOfElements];

    printf("Enter elements:\n");
    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &elements[i]);
    }

    
    printf("Enter element to search for: ");
    scanf("%d", &search);

    for (int i = 0; i < numberOfElements; i++) {
        if (elements[i] == search) {
            printf("Element found at index %d\n", i);
            break;
        }
    }

    return 0;
}
