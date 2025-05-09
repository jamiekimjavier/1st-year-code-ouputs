#include <stdio.h>

int main() {
    char password[100], confirmPassword[100];
    int i, match;

    printf("Set your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove the newline character from the password
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] == '\n') {
            password[i] = '\0';
            break;
        }
    }

    do {
        printf("Retype your password: ");
        fgets(confirmPassword, sizeof(confirmPassword), stdin);

        // Remove the newline character from the confirmation password
        for (i = 0; confirmPassword[i] != '\0'; i++) {
            if (confirmPassword[i] == '\n') {
                confirmPassword[i] = '\0';
                break;
            }
        }

        match = 1;
        for (i = 0; password[i] != '\0' || confirmPassword[i] != '\0'; i++) {
            if (password[i] != confirmPassword[i]) {
                match = 0;
                break;
            }
        }

        if (match) {
            printf("Password confirmed successfully!\n");
            break;
        } else {
            printf("Passwords do not match. Please try again.\n");
        }
    } while (1);

    return 0;
}
