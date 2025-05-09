#include <stdio.h>

int main() {
    
    int temperatureCount;
    int choice;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose conversion (1 or 2): ");
    scanf("%d", &choice);

    printf("How many temperatures do you want to convert? ");
    scanf("%d", &temperatureCount);
    
    float temperature[temperatureCount];
    float convertedTemperatures[temperatureCount];
    
    printf("Enter %d temperatures: \n", temperatureCount);

    for (int i = 0; i < temperatureCount; i++) {
        scanf("%f", &temperature[i]);
    }

    if (choice == 1) {
        printf("Converted Temperatures:\n");
        for (int i = 0; i < temperatureCount; i++) {
            convertedTemperatures[i] = (1.8 * temperature[i]) + 32;
            printf("%.2f°C = %.2f°F\n", temperature[i], convertedTemperatures[i]);
        }
    } else if (choice == 2) {
        printf("Converted Temperatures:\n");
        for (int i = 0; i < temperatureCount; i++) {
            convertedTemperatures[i] = 0.56 * (temperature[i] - 32);
            printf("%.2f°F = %.2f°C\n", temperature[i], convertedTemperatures[i]);
        }
    } else {
        printf("Invalid choice. Please choose 1 for Celsius to Fahrenheit or 2 for Fahrenheit to Celsius.\n");
    }


    return 0;

}