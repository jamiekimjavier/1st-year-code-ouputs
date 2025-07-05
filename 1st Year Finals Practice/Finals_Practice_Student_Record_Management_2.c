#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    float grade;
};

int main(void) {
    struct Student students[100];
    int size, i, j;
    int choice;
    int searchId, found = 0;
    float newGrade;

    FILE *fptr;

    printf("Student Record Management System");

    printf("\n  1. Add new student"
           "\n 2. Search and update student records"
           "\n 3. Sort student records"
           "\n 4. Write and display all student records"
           "\n 5. Exit program");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("How many students would you like to add? ");
                scanf("%d", &size);
                getchar();

                for (i = 0; i < size; i++) {
                    printf("Enter student %d information:\n", i + 1);

                    printf("ID: ");
                    scanf("%d", &students[i].id);
                    getchar();

                    printf("Name: ");
                    fgets(students[i].name, 100, stdin);
                    getchar();

                    printf("Age: ");
                    scanf("%d", &students[i].age);
                    getchar(); 

                    printf("Grade: ");
                    scanf("%f", &students[i].grade);
                    getchar();  
                }
                break;

            case 2:
                printf("Enter Search ID: ");
                scanf("%d", &searchId);
                getchar();  

                printf("Enter New Grade: ");
                scanf("%f", &newGrade);
                getchar();  

                found = 0;  

                for (i = 0; i < size; i++) {
                    if (searchId == students[i].id) {
                        students[i].grade = newGrade;
                        found = 1; 
                    }
                }

                if (!found) {
                    printf("\nRecord not found.\n");
                } else {
                    printf("\nRecord updated.\n");
                }
                break;

            case 3:
                
                for (i = 0; i < size; i++) {
                    for (j = 0; j < size - i - 1; j++) {
                        if (students[j].grade > students[j + 1].grade) {
                            struct Student temp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = temp;
                        }
                    }
                }

                printf("\nStudent records successfully sorted.\n");
                break;

            case 4:
                fptr = fopen("students_file_sample.txt", "w");

                if (fptr == NULL) {
                    printf("Error opening file.\n");
                    break;
                }

                printf("\nAll student records written to file:\n");
                for (i = 0; i < size; i++) {
                    fprintf(fptr, "Student %d info", i + 1);
                    fprintf(fptr, "ID: %d", students[i].id);
                    fprintf(fptr, "Name: %s", students[i].name);
                    fprintf(fptr, "Age: %d", students[i].age);
                    fprintf(fptr, "Grade: %.2f\n", students[i].grade);
                }

                fclose(fptr);

                fptr = fopen("students_file_sample.txt", "r");
                if (fptr != NULL) {
                    char line[1000];
                    while (fgets(line, sizeof(line), fptr)) {
                        printf("%s", line);
                    }
                    fclose(fptr);
                }
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

