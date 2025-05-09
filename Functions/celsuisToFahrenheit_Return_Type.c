#include <stdio.h>

float celsiusToFahrenheit (float celsius_temp, float fahrenheit_temp);

int main() {
    float celsius_temp, fahrenheit_temp;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius_temp);

    fahrenheit_temp = celsiusToFahrenheit (celsius_temp, fahrenheit_temp);

    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit_temp);

    return 0;
}

float celsiusToFahrenheit (float celsius_temp, float fahrenheit_temp) {
    return (celsius_temp * 9 / 5) + 32;
}
