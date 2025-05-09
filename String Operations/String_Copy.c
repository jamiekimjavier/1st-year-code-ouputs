#include <stdio.h>

int main(void) {
    char source[100];
    char destination[100]; 
    int i;

    printf("Enter a string: ");
    scanf("%99s", source);

    for(i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    destination[i] = '\0';

    printf("Source String: %s\n", source);
    printf("Destination String: %s\n", destination);

    return 0;
}