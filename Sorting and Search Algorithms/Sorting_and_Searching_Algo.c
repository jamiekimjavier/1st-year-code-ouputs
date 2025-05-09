#include <stdio.h>

int main (void) {

    int temperaturesNumber;

        printf("\n===================================="
                "\n|   CELSIUS TO FAHRENHEIT SORTER   |\n"
                "====================================\n");

    printf("Enter the number of temperatures: \n"
            "> ");
    scanf("%d", &temperaturesNumber);

    float celsius[temperaturesNumber];
    float fahrenheit[temperaturesNumber];
    float bubbleSorted[temperaturesNumber], insertionSorted[temperaturesNumber], selectionSorted[temperaturesNumber];

    printf("Enter %d temperatures in Celsius: \n", temperaturesNumber);
    
    for (int i = 0; i < temperaturesNumber; i++) {
        printf("> ");
        scanf("%f", &celsius[i]); 

        fahrenheit[i] = (celsius[i] * 9 / 5) + 32;
    } 

    printf("\n====================================\n"
            "|               OUTPUT:            |\n"
            "====================================\n");

            for (int i = 0; i < temperaturesNumber; i++) {
                bubbleSorted[i] = fahrenheit[i];
                insertionSorted[i] = fahrenheit[i];
                selectionSorted[i] = fahrenheit[i];
            }

        printf("\n============================================\n"
                "|  Sorted temperatures using Bubble Sort:  |\n"
                "============================================\n");


            for (int i = 0; i < temperaturesNumber -1; i++) {
                int swapped = 0;
                for (int j = 0; j < temperaturesNumber -i -1; j++) {
                    if (bubbleSorted[j] > bubbleSorted[j + 1]) {
                        float temp = bubbleSorted[j];
                        bubbleSorted[j] = bubbleSorted[j + 1];
                        bubbleSorted[j + 1] = temp;

                        swapped = 1;
                    }
                }
                if (swapped == 0) {
                    break;
                }
            }

        for (int i = 0; i < temperaturesNumber; i++) {
            printf("%.2f  ", bubbleSorted[i]);
        }

        printf("\n===============================================\n"
                "|  Sorted temperatures using Insertion Sort:  |\n"
                "===============================================\n");

            for (int i = 0; i < temperaturesNumber; i++) {
                float current = insertionSorted[i];
                int j = i - 1;
                while (j >=0 && insertionSorted[j] > current) {
                    insertionSorted[j + 1] = insertionSorted[j];
                    j--;
                }
                insertionSorted[j + 1] = current;
            }

        for (int i = 0; i < temperaturesNumber; i++) {
            printf("%.2f  ", insertionSorted[i]);
        }

        printf("\n===============================================\n"
                "|  Sorted temperatures using Selection Sort:  |\n"
                "===============================================\n");

            for (int i = 0; i < temperaturesNumber; i++) {
                int minIndex = i;

                for (int j = i + 1; j < temperaturesNumber; j++) {
                    if (selectionSorted[j] < selectionSorted[minIndex]) {
                        minIndex = j;
                    }
                }
                float temp = selectionSorted[i];
                selectionSorted[i] = selectionSorted[minIndex];
                selectionSorted[minIndex] = temp;
            }

        for (int i = 0; i < temperaturesNumber; i++) {
            printf("%.2f  ", selectionSorted[i]);
        }


    return 0;
}