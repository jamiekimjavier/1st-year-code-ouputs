#include <stdio.h>

int main() {
    int numberOfElements;
    int choice;
    
    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);

    int elements[numberOfElements];

    printf("Enter the elements: \n");
    for (int i = 0; i < numberOfElements; i++) {
        scanf("%d", &elements[i]);
    }

    printf("Enter 1 to display even numbers, 2 to display odd numbers: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("Even Numbers: ");
            for (int i = 0; i < numberOfElements; i++) {
                if (elements[i] % 2 == 0) {
                    printf("%d ", elements[i]);
                }
                else {
                    continue;
                }
            }
        break;
        ;
        case 2 : 
            printf("Odd Numbers: ");
            for (int i = 0; i < numberOfElements; i++) {
                if (elements[i] % 2 == 0) {
                    continue;
                }
                else {
                    printf("%d ", elements[i]);
                }
            }
        break;
        ;
        default:
            printf("Enter 1 or 2 only ");
        break;
        ;
    }

    return 0;
}