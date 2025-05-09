#include <stdio.h>

int main(void) {

    int numberOfElements;
    int searchElement;
    int count = 0;

    
    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);

    int elements[numberOfElements];

    printf("Enter the elements: \n");
    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &elements[i]);
    }

    printf("Enter the element to count occurrences: ");
    scanf("%d", &searchElement);

    for (int i = 0; i < numberOfElements; i++) {
        if (elements[i] == searchElement) {
            count++;
        }
    }

    printf("The element %d occurs %d times in the array.\n", searchElement, count);

    return 0;
}
