#include <stdio.h>

int main(void) {

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Hello, %s. Nice to meet you! \n", name);


    return 0;
}