#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    char category[50];
    int quantity;  
};

int main(void) {
    int choice;
    struct Book book[100];  
    
    do {
        printf("Menu: ");
        printf("\n 1: Add new book"
               "\n 2: Display all books"
               "\n 3: Search for books by title, author or category"
               "\n 4: Exit");
        
        scanf("%d", &choice);
        getchar();  
    
        switch (choice) {
            case 1: 
                for (int i = 0; i < 100; i++) {
                    if (book[i].id == 0) { 
                        printf("Add new book:\n");
                        
                        printf("ID: ");
                        scanf("%d", &book[i].id);
                        getchar(); 
                        
                        printf("Title: ");
                        fgets(book[i].title, sizeof(book[i].title), stdin);
                        book[i].title[strcspn(book[i].title, "\n")] = '\0';
                        
                        printf("Author: ");
                        fgets(book[i].author, sizeof(book[i].author), stdin);
                        book[i].author[strcspn(book[i].author, "\n")] = '\0'; 
                        
                        printf("Category: ");
                        fgets(book[i].category, sizeof(book[i].category), stdin);
                        book[i].category[strcspn(book[i].category, "\n")] = '\0'; 
                        
                        printf("Quantity: ");
                        scanf("%d", &book[i].quantity);
                        
                        FILE *fptr = fopen("library.txt", "a");
                        if (fptr == NULL) {
                            printf("Error opening file.\n");
                            return 1;
                        }
                        
                        fprintf(fptr, "ID: %d, Title: %s, Author: %s, Category: %s, Quantity: %d\n",
                                book[i].id, book[i].title, book[i].author, book[i].category, book[i].quantity);
                        
                        fclose(fptr);
                        printf("Book added successfully!\n");
                        break;
                    }
                }
                break;

            case 2: 
                {
                    FILE *fptr;
                    fptr = fopen("library.txt", "r");
                    
                    if (fptr == NULL) {
                        printf("Error opening file.\n");
                        return 1; 
                    }
                    
                    char line[200]; 
                    while (fgets(line, sizeof(line), fptr)) {
                        printf("%s", line); 
                    }
                    
                    fclose(fptr);
                }
                break;

				 case 3: //search/filter
				{
				    char search[50];
				
				    printf("Enter filter/search term by title, author or category: ");
				    scanf("%s", search);
				    getchar();
				
				    FILE *fptr = fopen("library.txt", "r");
				    if (fptr == NULL) {
				        printf("Error opening file.\n");
				        return 1;
				    }
				
				    char line[200];
				    while (fgets(line, sizeof(line), fptr)) {
				        int id;
				        char title[50];
				        char author[50];
				        char category[50];
				        int quantity;
				
				        if (sscanf(line, "ID: %d, Title: %49[^,], Author: %49[^,], Category: %49[^,], Quantity: %d", 
				            &id, title, author, category, &quantity) == 5) {
				            
				            if (strstr(title, search) != NULL || strstr(author, search) != NULL || strstr(category, search) != NULL) {
				                printf("%s", line);  
				            }
				        }
				    }
				
				    fclose(fptr);
				}
				break;


            case 4:
            	 printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

