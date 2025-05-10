#include <stdio.h>

float bmiCalculator(float weight, float height);

int main() {
    float weight, height;

    printf("BMI (Body Mass Index) is a measure of body fat based on weight and height that applies to adult men and women.\n");

    printf("Enter weight in kilograms: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    float bmi = bmiCalculator(weight, height);
    printf("Your calculated BMI is: %.2f\n", bmi);

        if (bmi < 18.5) {
        printf("Classification: Underweight");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("Classification: Normal Weight");
    } else if (bmi >= 25.0 && bmi <= 29.9) {
        printf("Classification: Overweight");
    } else if (bmi >= 30.0) {
        printf("Classification: Obese");
    }

    return 0;
}

float bmiCalculator(float weight, float height) {
        float calculatedBmi = weight / (height * height);
    return calculatedBmi;
}