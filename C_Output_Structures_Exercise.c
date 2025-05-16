#include <stdio.h>
#include <string.h>

#define SIZE 5

struct Student {
    char name[50];
    int studentNum;
    int age;
    double grade;
};

double average(struct Student students[], int size);
int oldestStudent(struct Student students[], int size);
void displayStudents(struct Student students[], int size);




int main() {
    struct Student students[SIZE];

    printf("Enter details for %d students:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Student Number: ");
        scanf("%d", &students[i].studentNum);
        printf("Age: ");
        scanf("%d", &students[i].age);

        do {
            printf("Grade (1-100): ");
            scanf("%lf", &students[i].grade);

            if (students[i].grade < 1.0 || students[i].grade > 100.0) {
                printf("Invalid grade! Please enter a grade between 1 and 100.\n");
            }
        } while (students[i].grade < 1.0 || students[i].grade > 100.0);
    }

    printf("\nAll Student Details: \n");
    displayStudents(students, SIZE);

    double avg = average(students, SIZE);
    printf("\nAverage Grade: %.2f\n", avg);

    int index = oldestStudent(students, SIZE);
    printf("\nOldest Student: \n");
    printf("Name: %s\n", students[index].name);
    printf("Student Number: %d\n", students[index].studentNum);
    printf("Age: %d\n", students[index].age);
    printf("Grade: %.2f\n", students[index].grade);

    return 0;
}




double average(struct Student students[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += students[i].grade;
    }
    return total / size;
}

int oldestStudent(struct Student students[], int size) {
    int maxAge = students[0].age;
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (students[i].age > maxAge) {
            maxAge = students[i].age;
            index = i;
        }
    }
    return index;
}

void displayStudents(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Student Number: %d\n", students[i].studentNum);
        printf("Age: %d\n", students[i].age);
        printf("Grade: %.2f\n", students[i].grade);
    }
}
