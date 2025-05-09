#include <stdio.h>

float calculateSales(int array[]);
void evaluatePerformance(int totalSales);

int main(){
    int array[7];

    printf("Enter the sales for 7 days: \n");

    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Total Sales: %.2f\n", calculateSales(array));
    evaluatePerformance(calculateSales(array));

    return 0;
}

float calculateSales(int array[]) {
    float sum = 0;
    for (int i = 0; i < 7; i++) {;
    sum += array[i];
    }
    return sum;
}

void evaluatePerformance(int totalSales) {
    if (totalSales > 50000) {
        printf("Performance: Excellent");
    } else if (totalSales >= 20000 && totalSales <= 50000) {
        printf("Performance: Good");
    } else if (totalSales < 20000) {
        printf("Performance: Needs Improvement");
    }
}


