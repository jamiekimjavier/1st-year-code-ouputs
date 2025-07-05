#include <stdio.h>

struct Student {
    char name[50];
    int age;
    int studentId;
    float grade;
};

void updateGrade(struct Student students[], int size);
float average(struct Student students[], int size);
int writeToFile(struct Student students[], int size);
void displayStudents(struct Student students[], int size);

int main() {
    int size, choice;
    struct Student students[100];

        printf("\n========================================="
            "\n|        STUDENT GRADE MANAGER          |"
            "\n=========================================\n");

    printf("\n> How many students do you want to enter? ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("\n======= Enter Details for Student #%d =======\n", i + 1);
        printf("Enter Name: ");
        getchar();
        fgets(students[i].name, sizeof(students[i].name), stdin);

        printf("Enter Age: ");
        scanf("%d", &students[i].age);
        
        printf("Enter Student ID: ");
        scanf("%d", &students[i].studentId);

        printf("Enter Grade: ");
        scanf("%f", &students[i].grade);
    }

        do {
        printf("\n============== MENU ==============\n");
        printf("1. Write to File and Display to Console\n");
        printf("2. Update Student Grade\n");
        printf("3. Show Average Grade\n");
        printf("4. Exit\n");
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                writeToFile(students, size);
                printf("\nData written to file successfully\n");

                displayStudents(students, size);
                break;
            case 2:
                updateGrade(students, size);
                break;
            case 3:
            {
                    float avg = average(students, size);
                    printf("\nThe average grade of the students is: %.2f\n", avg);
            }
                break;
            case 4:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

void updateGrade(struct Student students[], int size) {
    float newGrade;
    int searchID, found = 0;

    printf("\n> Enter the ID of the student to update grade: ");
    scanf("%d", &searchID);

    printf("Enter new grade: ");
    scanf("%f", &newGrade);

    for (int i = 0; i < size; i++) {
        if (searchID == students[i].studentId) {
            students[i].grade = newGrade;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found.\n", searchID);
    }
}

float average(struct Student students[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += students[i].grade;
    }
    return total / size;  
}

int writeToFile(struct Student students[], int size) {
    FILE *fptr;

    fptr = fopen("students_file.txt", "w");

    if(fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fptr, "\n======= Student #%d Info =======\n", i + 1);
        fprintf(fptr, "Name: %s", students[i].name); 
        fprintf(fptr, "Age: %d\n", students[i].age);
        fprintf(fptr, "ID: %d\n", students[i].studentId);
        fprintf(fptr, "Grade: %.2f\n", students[i].grade);
    }

    fclose(fptr);
    return 0;
}

void displayStudents(struct Student students[], int size) {
    FILE *fptr = fopen("students_file.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }
    fclose(fptr);
}

