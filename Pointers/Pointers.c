#include <stdio.h>

void addNumber(int *numPointer, int *arrPointer, int *sizePointer);
void viewNumbers(int *arrPointer, int *sizePointer);
int computeTotal(int *arrPointer, int *sizePointer);

int main(void) {
    
    int number, arr[100], choice;
    int size = 0;

    int *numPointer = &number;
    int *arrPointer = arr;
    int *sizePointer = &size;
    
    do {
        printf("\n=============================================="
                "\n|    Simple Menu Program Using Pointers    |\n"
                "==============================================\n"
                "| [1] Add Number                  |\n"
                "| [2] View Numbers                |\n"
                "| [3] Compute Total               |\n"
                "| [4] Exit                        |\n"
                "==============================================\n");

        printf("Enter your choice : ");
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid input! Please enter a valid number between 1 and 4.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: 
                printf("=====[ADD NUMBER]=====\n");
                printf("Enter a number to add: ");
                scanf("%d", numPointer);

                addNumber(numPointer, arrPointer, sizePointer);
                printf("Number added successfully.\n");
                break;

            case 2:
                printf("=====[VIEW NUMBERS]=====\n");
                printf("Stored Numbers: ");
                viewNumbers(arrPointer, sizePointer);
                break;

            case 3:
                printf("=====[COMPUTE TOTAL]=====\n");
                printf("Total of all numbers: %d\n", computeTotal(arrPointer, sizePointer));
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");  
        }
    } while (choice != 4);

    return 0;
}

void addNumber(int *numPointer, int *arrPointer, int *sizePointer) {
    if (*sizePointer >= 100) {
        printf("Sorry! This array is already full. You may not add any more numbers.\n");
        return;
    } else {
        *(arrPointer + *sizePointer) = *numPointer;
        (*sizePointer)++;
    }
}

void viewNumbers(int *arrPointer, int *sizePointer) { 
    if (*sizePointer == 0) {
        printf("Sorry, but there are currently no numbers to display as the array is empty.\n");
    } else {
        for (int i = 0; i < *sizePointer; i++) {
            printf("%d ", *(arrPointer + i)); 
        }
        printf("\n");
    }
}

int computeTotal(int *arrPointer, int *sizePointer) {
    int total = 0;
    for (int i = 0; i < *sizePointer; i++) {
        total += *(arrPointer + i);
    }
    return total;
}
