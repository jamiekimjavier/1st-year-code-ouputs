#include <stdio.h>

int sumOfElements(int num_elements, int numbers[]);

int main() {
    int num_elements;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &num_elements);

    int numbers[num_elements];

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &numbers[i]);
    }

    int sum = sumOfElements(num_elements, numbers);

    printf("Sum of all elements: %d\n", sum);

    return 0;
}

int sumOfElements(int num_elements, int numbers[]) {
    int sum = 0;

    for (int i = 0; i < num_elements; i++) {
        sum += numbers[i];
    }

    return sum;
}
