#include <stdio.h>

int main(void) {
    
    char input;

    printf("Enter a character: ");
    scanf("%c", &input);

    if ((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')) {
        if (input >= 'A' && input <= 'Z') {
            printf("The character is an uppercase letter.\n");
        } else {
            printf("The character is a lowercase letter.\n");
        }
    } else if (input >= '0' && input <= '9') {
        printf("The character is a digit.\n");
    } else {
        printf("The character is neither an alphabetical letter nor a digit.\n");
    }

    return 0;
}

