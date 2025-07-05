#include <stdio.h>
#include <string.h>

struct Expense {
    char date[11];        
    char category[50];   
    char description[100];
    float amount;         
};

void addExpense();
void viewExpenses();
void filterExpenses();
void calculateTotalExpenses();
void displayMenu();

int main(void) {
    int choice;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Add new expense\n");
        printf("2. View all expenses\n");
        printf("3. Filter expenses by date or category\n");
        printf("4. Calculate total expenses\n");
        printf("5. Exit\n");
    
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                filterExpenses();
                break;
            case 4:
                calculateTotalExpenses();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addExpense() {
    struct Expense expense;

    printf("Enter expense details:\n");
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", expense.date); 
    getchar();
    
    printf("Category: ");
    fgets(expense.category, sizeof(expense.category), stdin);
    expense.category[strcspn(expense.category, "\n")] = '\0';
    
    printf("Description: ");
    fgets(expense.description, sizeof(expense.description), stdin);
    expense.description[strcspn(expense.description, "\n")] = '\0'; 

    printf("Amount: ");
    scanf("%f", &expense.amount); 
    getchar(); 

    FILE *fptr = fopen("expenses.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fptr, "%s, %s, %s, %.2f\n", expense.date, expense.category, expense.description, expense.amount);
    fclose(fptr);

    printf("Expense added successfully.\n");
}

void viewExpenses() {
    FILE *fptr = fopen("expenses.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[1000];
    printf("\nRecorded Expenses:\n");
    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }
    fclose(fptr);
}

void filterExpenses() {
    char filter[50];
    printf("Enter date (YYYY-MM-DD) or category to filter: ");
    fgets(filter, sizeof(filter), stdin);
    filter[strcspn(filter, "\n")] = '\0';

    FILE *fptr = fopen("expenses.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[1000];
    printf("\nFiltered Expenses:\n");
    while (fgets(line, sizeof(line), fptr)) {
        char date[11], category[50], description[100];
        float amount;
        sscanf(line, "%10[^,], %49[^,], %99[^,], %f", date, category, description, &amount);

        if (strcmp(date, filter) == 0 || strcmp(category, filter) == 0) {
            printf("%s", line);
        }
    }
    fclose(fptr);
}

void calculateTotalExpenses() {
    char filter[50];
    float total = 0.0;
    printf("Enter date (YYYY-MM-DD) or category to calculate total: ");
    fgets(filter, sizeof(filter), stdin);
    filter[strcspn(filter, "\n")] = '\0';

    FILE *fptr = fopen("expenses.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), fptr)) {
        char date[11], category[50], description[100];
        float amount;
        sscanf(line, "%10[^,], %49[^,], %99[^,], %f", date, category, description, &amount);

        if (strcmp(date, filter) == 0 || strcmp(category, filter) == 0) {
            total += amount;
        }
    }
    fclose(fptr);

    printf("Total expenses for '%s': %.2f\n", filter, total);
}

