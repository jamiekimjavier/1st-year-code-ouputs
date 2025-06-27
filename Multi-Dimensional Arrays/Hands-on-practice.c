#include <stdio.h>

int main (void) {

    //declarations
    float total, average;
    float grandTotal, overallAverage;
    float array[3][7];

    
    printf("\nInput Exercise Data:");
    
    for (int i = 0; i < 3; i++) { //per activity, reset total and mention activity
    total = 0;
    
    if (i == 0){
        printf("\nActivity %d: Jogging\n", i + 1);
    }  else if (i == 1){
        printf("\nActivity %d: Swimming\n", i + 1);
    }  else if (i == 2){
        printf("\nActivity %d: Walking\n", i + 1);
    }

        for (int j = 0; j < 7; j++) {
            //get user input for 7 durations per activity
            printf("Duration for day %d: ", j + 1);
            scanf("%f", &array[i][j]);

            total += array[i][j];

        }
    
    //after each activity and inputs, get average while di pa nagrereset yung total and define recommendation
        average = total / 7.0;
        printf("Average Duration for Activity %d: %.2f minutes", i + 1, average);
        if (average < 40.0) {
            printf("\nRecommendation: Increase intensity for better results.\n");
        } else if (average < 50.0) {
            printf("\nRecommendation: Maintain current level.\n");
        } else if (average > 50.0) {
            printf("\nRecommendation: Excellent! Maintain current level.\n");
        }

    //gather grand totals from each activity accumulating it while di pa nagrereset total
        grandTotal += total;

    }

    //get grand totals and average
    overallAverage = grandTotal / 21.0;
    printf("\nOverall Performance: ");
    printf("\nAverage Duration: %.2f minutes", overallAverage);
            if (overallAverage < 40.0) {
            printf("\nRecommendation: Increase intensity for better results.");
        } else if (overallAverage < 50.0) {
            printf("\nRecommendation: Maintain current level.");
        } else if (overallAverage > 50.0) {
            printf("\nRecommendation: Excellent! Maintain current level.");
        }

    
}
