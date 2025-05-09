#include <stdio.h>

int main() {
    int choice;

    while (1) {
        printf("\n      Menu:\n");
        printf("================\n");
        printf("1. Play Game\n");
        printf("2. Load Game\n");
        printf("3. Exit\n");
        printf("================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Playing game...\n");
                break;
            case 2:
                printf("Loading game...\n");
                break;
            case 3:
                printf("Exiting program. Adios!\n");
                return 0; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
