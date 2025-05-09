#include <stdio.h>

int findMax(int *ptr, int size);

int main() {
    int array[] = {10, 23, 5, 18, 32, 7};
    int size = sizeof(array) / sizeof(array[0]);
    int max = findMax(array, size);
    printf("The maximum element in the array is: %d\n", max);
    return 0;
}

int findMax(int *ptr, int size) {

    int max = 0;

    for (int i = 0; i < size; i++){
        if (max < ptr[i]) {
            max = ptr[i];
        }
    }

    return max;
}
