#include <stdio.h>

int main (void){

    char seats[5][10] = {
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    };

    int row, column, choice;

    printf("====== Welcome to the Cinema! ======");
    printf("\n");

    do {
    printf("\n==================================="
          "\n|  Cinema Seat Reservation System |\n"
            "===================================\n"
            "| [1] Display seating chart       |\n"
            "| [2] Reserve a seat              |\n"
            "| [3] Cancel a reservation        |\n"
            "| [4] Exit                        |\n"
            "===================================\n");
    printf(">Enter your choice: ");
    scanf("%d", &choice);


    switch(choice) {
        case 1:

        printf("        \n=====[SEATING CHART]===== \n");
        printf("        0 1 2 3 4 5 6 7 8 9");
        for (int i = 0; i < 5; i++) {
            printf("\n Row %d: ", i);
            for (int j = 0; j < 10; j++) {
                printf("%c ", seats[i][j]);
            }
        }

        break;

        case 2:

        
            printf("=====[RESERVE A SEAT]===== \n");
            printf("\nEnter row [0-4] to reserve: ");
            scanf("%d", &row);
            printf("Enter column [0-9] to reserve: ");
            scanf("%d", &column);

        if(row >= 0 && row <= 4 && column >= 0 && column <= 9) {
            if (seats[row][column] == 'A') {
                seats[row][column] = 'R';
                printf("Seat in Row %d, Column %d has been reserved! \n", row, column);
            } else {
                printf("Sorry, but that seat is already taken.");
            }
        } else {
            printf("Row or column entered is out of range! Please try again.\n");
        }

        break;

        case 3:

        printf("=====[CANCEL A RESERVATION]=====\n");
        printf("\nEnter row [0-4] to cancel: ");
        scanf("%d", &row);
        printf("Enter column [0-9] to cancel: ");
        scanf("%d", &column);

        if(row >= 0 && row <= 4 && column >= 0 && column <= 9) {
            if (seats[row][column] == 'R') {
                seats[row][column] = 'A';
                printf("Reservation for seat in Row %d, Column %d has been cancelled! \n", row, column);
            } else {
                printf("This seat is already available.\n");
            }
        } else {
            printf("Row or column entered is out of range! Please try again.\n");
        }

        break;

        case 4:
        printf("Exiting the program...");

        break;

        default: 
        printf("Invalid choice! Please try again.\n");  
        
        }

    } while (choice != 4);  

    return 0;
}
