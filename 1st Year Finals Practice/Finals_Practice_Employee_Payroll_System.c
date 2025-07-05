#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    int hoursWorked;
    float wage;
    char department[50];
};

int main(void) {
    struct Employee employees[100];
    int choice = 0;
    int employeeCount = 0;

    printf("Menu: ");
    printf("\n1: Add new employee");
    printf("\n2: Display all employees");
    printf("\n3: Search for employee by id");
    printf("\n4: Exit");

    do {
        printf("\nChoose: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                for (int i = 0; i < 100; i++) {
                    printf("\n Add Employee: ");
                    
                    printf("\n ID: ");
                    scanf("%d", &employees[i].id);
                    getchar();
                    
                    printf("Name: ");
                    fgets(employees[i].name, sizeof(employees[i].name), stdin);
                    employees[i].name[strcspn(employees[i].name, "\n")] = '\0';
                    
                    printf("Hours Worked: ");
                    scanf("%d", &employees[i].hoursWorked);
                    getchar();
                    
                    printf("Wage: ");
                    scanf("%f", &employees[i].wage);
                    getchar();
                    
                    printf("Department: ");
                    scanf("%s", employees[i].department);
                    getchar();
                    
                    FILE *fptr = fopen("employee_payroll.txt", "a");
                    fprintf(fptr, "%d, %s, %d, %f, %s \n", employees[i].id, employees[i].name, employees[i].hoursWorked, employees[i].wage, employees[i].department);
                    
                    printf("Total payroll: %.2f\n", employees[i].hoursWorked * employees[i].wage);
                    
                    fclose(fptr);
                    employeeCount++;
                    
                    printf("Added employee successfully");
                    break;
                }
            } break;
            case 2: {
                FILE *fptr = fopen("employee_payroll.txt", "r");
                
                char line[1000];
                
                while(fgets(line, sizeof(line), fptr)) {
                    printf("%s", line);
                }
                
                fclose(fptr);
            } break;
            case 3: { // Search by ID
                int searchId;
                printf("\nEnter the employee ID to search for: ");
                scanf("%d", &searchId);
                getchar();
                
                int found = 0;
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].id == searchId) {
                        printf("\nEmployee found!\n");
                        printf("ID: %d\n", employees[i].id);
                        printf("Name: %s\n", employees[i].name);
                        printf("Hours Worked: %d\n", employees[i].hoursWorked);
                        printf("Wage: %.2f\n", employees[i].wage);
                        printf("Department: %s\n", employees[i].department);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nEmployee with ID %d not found.\n", searchId);
                }
            } break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                break;
        }

    } while (choice != 0);

    return 0;
}

