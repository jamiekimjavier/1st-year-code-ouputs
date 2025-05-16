#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size);

int main(void) {
    int size;
    int *array;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    array = (int *)malloc(size * sizeof(int));
    
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    bubbleSort(array, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
