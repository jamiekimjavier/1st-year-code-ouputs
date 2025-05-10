#include <stdio.h>

float gradeAverage(float grade[], int students);

int main() {
    int students;
    
    printf("Enter the number of students in a class: ");
    scanf("%d", &students);

    float grade[students];

    for (int i = 0; i < students; i++) {
        printf("Enter the student %d grade: ", i + 1);
        scanf("%f", &grade[i]);    
    }

    float average = gradeAverage(grade, students);

    printf("The average grade of the class is %.2f\n", average);
    
    return 0;
}

float gradeAverage(float grade[], int students) {
    float total = 0;
    for (int i = 0; i < students; i++) {
        total += grade[i];
    }
    return (float)total / students;
    
    
}