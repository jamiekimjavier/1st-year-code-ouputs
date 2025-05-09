#include <stdio.h>

int main() {
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    int array1[size1];

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    int array2[size2];

    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }

    //tas dito memerge yung 2 array

    int mergedArray[size1 + size2];

    for (int i = 0; i < size1; i++) {
        mergedArray[i] = array1[i];
    }

    //dito aadd yung elements nung 2nd array, para magawa yun gawin mo lang size yung max yung 1st array + i
    for (int i = 0; i < size2; i++) {
        mergedArray[size1 + i] = array2[i];
    }

    printf("Merged array:\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}