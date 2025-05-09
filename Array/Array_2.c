#include <stdio.h>

int main() {

    //Exercise Temp Analyzer kinemerut
    int temperature[7];
    int highest;
    float average;
    int highestDay;
    int sum = 0;
    

    for (int i = 0; i < 7; i++) {
        printf("Enter temperature for day %d:", i + 1);
        scanf("%d", &temperature[i]);
    }

    for (int i = 0; i < 7 ; i++) {
        sum += temperature[i];
        if (i == 0) {
            highest = temperature[i];
            highestDay = i + 1;
        } else if (temperature[i] > highest){
            highest = temperature[i];
            highestDay = i + 1;
        }
    }
    average = sum / 7.0;

    printf("Average temperature: %.2f\n", average);
    printf("Highest temperature: %d on day %d\n", highest, highestDay);

    return 0;

}