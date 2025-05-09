#include <stdio.h>
#include <string.h>

int main(void) {
    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    int length = strlen(name);

    if (length % 2 == 0) {
        printf("You should join line 1\n");
    } else if (length % 2 == 1) {
        printf("You should join line 2\n");
    }

    return 0;
}