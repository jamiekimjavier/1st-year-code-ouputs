#include <stdio.h>

int main (void) {
    int arr[3][4];

    printf("Enter the elements of the 2D array: \n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter value for row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The elements of 2D array: \n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
        

    return 0;
}