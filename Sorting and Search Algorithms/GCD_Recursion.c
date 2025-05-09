#include <stdio.h>

int gcdFinder(int a, int b);

int main(){
    int a, b;

        printf("\n==============================\n"
            "      GCD RECURSION DEMO      \n"
            "==============================\n");


    printf(">Enter two integers: \n");
    if (scanf("%d", &a) != 1 || scanf("%d", &b) != 1) {
        printf("Invalid input! Please enter valid integers only.\n");
        return 1; 
    }

    int result = gcdFinder(a, b);

    printf("\n------------------------------\n");
    printf("The GCD of integers %d and %d is: %d", a, b, result);
    printf("\n------------------------------\n");

    return 0;
}

int gcdFinder(int a, int b) {
    if (b == 0)
        return a;
    return gcdFinder(b, a % b);

}