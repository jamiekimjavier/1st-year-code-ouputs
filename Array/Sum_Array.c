#include <stdio.h>

int main() {

    int numberOfElements;
    
    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);

    int elements[numberOfElements];

    printf("Enter the elements: \n");

    for(int i = 0; i < numberOfElements; i++) {
        scanf("%d", &elements[i]);
    }


    int sum = 0;
    for (int i = 0; i < numberOfElements; i++) {
        sum += elements[i];
    }

    printf("Sum of elements: %d", sum);

    return 0;
}