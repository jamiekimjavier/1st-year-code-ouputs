#include <stdio.h>

int main(void) {
    char studentName[50]; 
    char studentId[50];
    int mathGrade;
    int scienceGrade;
    int englishGrade;
    float averageGrade;
    

        printf("Enter student name: ");
        fgets(studentName, sizeof(studentName), stdin);

        printf("Enter student ID: ");
        scanf("%s", &studentId);
        
        printf("Enter grade in Math: ");
        scanf("%d", &mathGrade);
        
        printf("Enter grade in Science: ");
        scanf("%d", &scienceGrade);
        
        printf("Enter grade in English: ");
        scanf("%d", &englishGrade);
    
        printf("\n");
        printf("Student Name: %s", studentName);
        printf("Student ID: %s \n", studentId);
        printf("Grade in Math: %.2f \n", (float)mathGrade);
        printf("Grade in Science: %.2f \n", (float)scienceGrade);
        printf("Grade in English: %.2f \n", (float)englishGrade);
        
        printf("=========================\n");
        
        averageGrade = (mathGrade + scienceGrade + englishGrade) / 3.0;
        
        printf("Average Grade: %.2f \n", (float)averageGrade);
        
        if (averageGrade >= 75) {
            printf("Result: Passed \n");
        }
        else {
            printf("Result: Failed \n");
        }
        
    

    return 0;
}
