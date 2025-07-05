#include <stdio.h>
#include <string.h>

struct Exercise {
    float durations[3][7];
    char activityName[20]; 
    float averageResults[3];
};

int main(void) {
    struct Exercise exerciseArray[3];
    float total, grandTotal = 0, overallAverage;

    strcpy(exerciseArray[0].activityName, "Jogging");
    strcpy(exerciseArray[1].activityName, "Weightlifting");
    strcpy(exerciseArray[2].activityName, "Swimming");

    printf("\n===Fitness Tracker Analysis===\n");

    for (int i = 0; i < 3; i++) {
        total = 0;

        printf("\nEnter duration (in minutes) for %s for 7 days:\n", exerciseArray[i].activityName);

        for (int j = 0; j < 7; j++) {
            printf("Day %d: ", j + 1);
            scanf("%f", &exerciseArray[i].durations[i][j]); 

            total += exerciseArray[i].durations[i][j];
        }

        exerciseArray[i].averageResults[i] = total / 7.0;

        printf("\nAverage Duration for %s: %.1f minutes", exerciseArray[i].activityName, exerciseArray[i].averageResults[i]);

        if (exerciseArray[i].averageResults[i] < 40.0) {
            printf("\nRecommendation: Increase intensity for better results.\n");
        } else if (exerciseArray[i].averageResults[i] < 50.0) {
            printf("\nRecommendation: Maintain current level.\n");
        } else if (exerciseArray[i].averageResults[i] > 50.0) {
            printf("\nRecommendation: Excellent! Maintain current level.\n");
        }

        grandTotal += total;
    }

    overallAverage = grandTotal / 21.0;

    printf("\n===Overall Performance===\n");
    printf("\nAverage Duration: %.1f minutes", overallAverage);

    if (overallAverage < 40.0) {
        printf("\nRecommendation: Increase intensity for better results.\n");
    } else if (overallAverage < 50.0) {
        printf("\nRecommendation: Maintain current level.\n");
    } else if (overallAverage > 50.0) {
        printf("\nRecommendation: Excellent! Maintain current level.\n");
    }

    return 0;
}

