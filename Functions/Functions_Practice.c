#include <stdio.h>

int Greet(const char name[]);

int main(){

    Greet("Julio");
    Greet("Vanessa");


    return 0;
}

int Greet(const char name[]){
    printf("Hello %s!\n", name);
}