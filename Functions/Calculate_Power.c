#include <stdio.h>
#include <math.h>

float calculatePower(float a, float b);

int main() {
    float a, b;

    printf("Enter the base.\n");
    scanf("%f", &a);
    printf("Enter the exponent.\n");
    scanf("%f", &b);

    printf("%f", calculatePower(a, b));

    return 0;
}

float calculatePower(float a, float b) {
    return pow(a, b);
}
