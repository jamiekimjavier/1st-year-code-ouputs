#include <stdio.h>

int main(void) {
    char str[100];
    char upperStr[100]; 
    int i = 0;

    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            upperStr[i] = str[i] - ('a' - 'A');
        } else {
            upperStr[i] = str[i];
        }
        i++; 
    }
    upperStr[i] = '\0';

    printf("Uppercase String: %s\n", upperStr);

    return 0;
}