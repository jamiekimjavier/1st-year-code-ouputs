#include <stdio.h>

    int main(void) {
        int age;
        float height;
        float weight;

        printf("Enter your age: ");
        scanf("%d", &age);

        printf("Enter your height in cm: ");
        scanf("%f", &height);
        
        printf("Enter your weight in kg: ");
        scanf("%f", &weight);

        printf("\n");
        printf("Age: %d \n", age);
        printf("Height: %.2f cm \n", height);
        printf("Weight: %.2f kg \n", weight);

        return 0;

    }