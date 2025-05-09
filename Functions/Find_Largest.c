#include <stdio.h>

int findLargest(int arr[], int size);

int main() {
    int arr[] = {2, 10, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The largest element in the array is: %d\n", findLargest(arr, size));

    return 0;
}

int findLargest(int arr[], int size) {
    int largest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}
