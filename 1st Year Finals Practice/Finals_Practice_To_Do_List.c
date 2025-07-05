#include <stdio.h>
#include <string.h>

struct Task {
    int taskid;
    char title[100];
    char description[100];
    char dueDate[100];
    char status[50];
};

void addTasks(struct Task taskArray[], int *size);
void viewTasks(struct Task taskArray[], int *size);
void markTaskAsDone(struct Task taskArray[], int size);
void viewDueOrOverdueTasks(const struct Task taskArray[], int size);
void deleteTask(struct Task taskArray[], int *size);

int main(void) {
    struct Task taskArray[100];
    int choice, size = 0;

    do {
        printf("Choice (1: Add, 2: View, 3: Mark Done, 4: View Due, 5: Delete, 6: Exit): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addTasks(taskArray, &size);
                break;
            case 2:
                viewTasks(taskArray, size);
                break;
            case 3:
                markTaskAsDone(taskArray, size);
                break;
            case 4:
                viewDueOrOverdueTasks(taskArray, size);
                break;
            case 5:
                deleteTask(taskArray, &size);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}


void addTasks(struct Task taskArray[], int *size) {
    int newTasks;
    printf("How many tasks would you like to add: ");
    scanf("%d", &newTasks);
    getchar();

    for (int i = *size; i < *size + newTasks; i++) {
        printf("ID: ");
        scanf("%d", &taskArray[i].taskid);
        getchar();

        printf("Title: ");
        fgets(taskArray[i].title, sizeof(taskArray[i].title), stdin);
        taskArray[i].title[strcspn(taskArray[i].title, "\n")] = '\0';

        printf("Description: ");
        fgets(taskArray[i].description, sizeof(taskArray[i].description), stdin);
        taskArray[i].description[strcspn(taskArray[i].description, "\n")] = '\0';

        printf("Due date (YYYY-MM-DD): ");
        fgets(taskArray[i].dueDate, sizeof(taskArray[i].dueDate), stdin);
        taskArray[i].dueDate[strcspn(taskArray[i].dueDate, "\n")] = '\0';

        strcpy(taskArray[i].status, "Pending");
    }

    *size += newTasks;

    FILE *fptr = fopen("expenses_all.txt", "w");
    if (!fptr) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < *size; i++) {
        fprintf(fptr, "Task %d\n", i + 1);
        fprintf(fptr, "ID: %d\n", taskArray[i].taskid);
        fprintf(fptr, "Title: %s\n", taskArray[i].title);
        fprintf(fptr, "Description: %s\n", taskArray[i].description);
        fprintf(fptr, "Due Date: %s\n", taskArray[i].dueDate);
        fprintf(fptr, "Status: %s\n\n", taskArray[i].status);
    }

    fclose(fptr);
    printf("Saved to file successfully\n");
}

//papakita lang lahat ng nasa file

void viewTasks(struct Task taskArray[], int *size) {
    FILE *fptr = fopen("expenses_all.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }

    fclose(fptr);
}

void markTaskAsDone(struct Task taskArray[], int size) {
    int id;
    printf("Enter task ID to mark as done: ");
    scanf("%d", &id);
    getchar();
	
	//hanapin lang id tapos mamark as done
	
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (taskArray[i].taskid == id) {
            strcpy(taskArray[i].status, "Done");
            printf("Task ID %d marked as done.\n", id);
            found = 1;
            break;
        }
    }
    if (!found) printf("Task ID %d not found.\n", id);
}

void viewDueOrOverdueTasks(const struct Task taskArray[], int size) {
    char currentDate[100];
    printf("Enter current date (YYYY-MM-DD): ");
    fgets(currentDate, sizeof(currentDate), stdin);
    currentDate[strcspn(currentDate, "\n")] = '\0';
    
    //ez ez cocompare lang sa current date na lalagay

    int found = 0;
    printf("Tasks due today or overdue:\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(taskArray[i].dueDate, currentDate) <= 0) {
            printf("Task %d\n", i + 1);
            printf("ID: %d\n", taskArray[i].taskid);
            printf("Title: %s\n", taskArray[i].title);
            printf("Description: %s\n", taskArray[i].description);
            printf("Due Date: %s\n", taskArray[i].dueDate);
            printf("Status: %s\n\n", taskArray[i].status);
            found = 1;
        }
    }
    if (!found) printf("No tasks due today or overdue.\n");
}

void deleteTask(struct Task taskArray[], int *size) {
    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    getchar();

    int found = 0;
    //if mamatch yung id na hinahanap mo, hahanapin niya then babawasan size
    for (int i = 0; i < *size; i++) {
        if (taskArray[i].taskid == id) {
            for (int j = i; j < *size - 1; j++) {
                taskArray[j] = taskArray[j + 1];
            }
            (*size)--;
            printf("Task ID %d deleted.\n", id);
            found = 1;
            break;
        }
    }
    if (!found) printf("Task ID %d not found.\n", id);
}

