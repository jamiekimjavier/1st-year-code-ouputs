#include <stdio.h>

    int main(void) {

        int mealOrder;
        int membershipStatus;
        float burger = 150;
        float chicken = 200;
        float pasta = 250;

        printf("Choose your meal (1 - Burger, 2 - Chicken, 3- Pasta): ");
        scanf("%d", &mealOrder);
        printf("Enter your membership status ( 1 - Regular, 2 - Premium): ");
        scanf("%d", &membershipStatus);

        switch (mealOrder) {
            case 1: //burger
                if (membershipStatus == 1) {
                     printf("Your final meal cost is: %.2f", (float)burger);
                } else if (membershipStatus == 2) {
                    printf("Your final meal cost is: %.2f", (float)burger - ((float)burger * 0.10));
                } else {
                    printf("Invalid membership status. Please enter 1 for Regular or 2 for Premium.");
                }
            break;
                case 2: //chicken
                if (membershipStatus == 1) {
                     printf("Your final meal cost is: %.2f", (float)chicken);
                } else if (membershipStatus == 2) {
                    printf("Your final meal cost is: %.2f", (float)chicken - ((float)chicken * 0.10));
                } else {
                    printf("Invalid membership status. Please enter 1 for Regular or 2 for Premium.");
                }
            break;
                case 3: //pasta
                if (membershipStatus == 1) {
                     printf("Your final meal cost is: %.2f", (float)pasta);
                } else if (membershipStatus == 2) {
                    printf("Your final meal cost is: %.2f", (float)pasta - ((float)pasta * 0.10));
                } else {
                    printf("Invalid membership status. Please enter 1 for Regular or 2 for Premium.");
                }
            break;
                default:
                    printf("Invalid Input");
                break;


        }


        return 0;
    }