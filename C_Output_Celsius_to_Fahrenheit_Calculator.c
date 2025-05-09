#include <stdio.h>

    int main(void){
        
        int celsius;
        int fahrenheit;

        printf("Enter Celsius to convert: ");
        scanf("%d",&celsius);

        fahrenheit = (celsius * 9/5) + 32;

        printf("Fahrenheit = %.2f degrees \n", (float)fahrenheit);


    }