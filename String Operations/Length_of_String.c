#include <stdio.h>

int main(void) {
    char string[100];
    int stringLength = 0;

    printf("Enter a string: ");
    scanf("%s", string);

    for (int i = 0; string[i] != '\0'; i++) {
        stringLength++;
    }

    printf("String Length: %d\n", stringLength);

    return 0;
}