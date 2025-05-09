#include <stdio.h>
#include <string.h>

int stringLength(char name[100]);

int main() {
    char name[100];

    printf("Enter the name: \n");
    scanf("%s", name);

    printf("%d", stringLength(name));

    return 0;
}

int stringLength(char name[100]) {
    return strlen(name);
}