#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int target, guess;

    srand(time(0));
    target = rand() % 100 + 1; 

    printf("Guess the number (between 1 and 100):\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < target) {
            printf("Too low. Try again.\n");
        } else if (guess > target) {
            printf("Too high. Try again.\n");
        } else {
            printf("Congrats! You have guessed the correct number!.\n");
            break;
        }
    }

    return 0;
}
