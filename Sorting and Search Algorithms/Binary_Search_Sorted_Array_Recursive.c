#include <stdio.h>

int binarySearch(int arr[], int lower, int upper, int search);

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int search;

    printf("\n==============================\n"
            "      BINARY SEARCH DEMO      \n"
            "==============================\n");

    printf(">Enter the search element: ");
    scanf("%d", &search);

    int result = binarySearch(arr, 0, size - 1, search);


    printf("\n------------------------------\n");
    if (result != -1) {
        printf("Element %d found at index %d.\n", search, result);
    } else { 
        printf("Element %d not found.\n", search);
    }
    printf("------------------------------\n\n");

    return 0;
}

int binarySearch(int arr[], int lower, int upper, int search) {
    if (lower > upper) {
        return -1; 
    }

    int mid = lower + (upper - lower) / 2;

    if (arr[mid] == search) {
        return mid;
    } else if (arr[mid] < search) {
        return binarySearch(arr, mid + 1, upper, search);
    } else {
        return binarySearch(arr, lower, mid - 1, search);
    }
}
