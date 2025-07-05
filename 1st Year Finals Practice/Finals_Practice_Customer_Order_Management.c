#include <stdio.h>
#include <string.h>

struct Item {
    char name[100];
    int quantity;
    float price;
};

struct Order {
    char customerName[100];
    int orderId;
    struct Item items[5];
    int itemCount;
    float totalAmount;
};

struct Order addOrder(struct Order order);
struct Order computeTotal(struct Order order);
void viewOrders();

int main(void) {
    int choice;
    struct Order order;

    do {
        printf("Enter your choice:\n");
        printf("1. Add new order\n");
        printf("2. View all orders\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                order = addOrder(order);
                order = computeTotal(order);

                FILE *fptr = fopen("orders.txt", "a");
                if (fptr == NULL) {
                    printf("Error opening file.\n");
                    break;
                }

                fprintf(fptr, "%s, %d", order.customerName, order.orderId);
                for (int i = 0; i < order.itemCount; i++) {
                    fprintf(fptr, ", %s x %d @ %.2f", order.items[i].name, order.items[i].quantity, order.items[i].price);
                }
                fprintf(fptr, ", Total: %.2f\n", order.totalAmount);
                fclose(fptr);

                printf("Order added successfully.\n");
                printf("Total amount: %.2f\n", order.totalAmount);
                break;

            case 2:
                viewOrders();
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}


struct Order addOrder(struct Order order) {
	//initialize dito
    order.itemCount = 0;
    order.totalAmount = 0.0;

	//for lahat ng order ni customer
    printf("Enter customer name: ");
    fgets(order.customerName, sizeof(order.customerName), stdin);
    order.customerName[strcspn(order.customerName, "\n")] = '\0';

    printf("Enter order ID: ");
    scanf("%d", &order.orderId);
    getchar();

    printf("Enter number of items (max 5): ");
    scanf("%d", &order.itemCount);
    getchar();
	
	//error checking lungss
    if (order.itemCount > 5) {
        printf("You can only add up to 5 items.\n");
        order.itemCount = 0;
        return order;
    }
    
    //for indiv items sa order

    for (int i = 0; i < order.itemCount; i++) {
        printf("Enter item %d details:\n", i + 1);
        printf("Name: ");
        fgets(order.items[i].name, sizeof(order.items[i].name), stdin);
        order.items[i].name[strcspn(order.items[i].name, "\n")] = '\0';

        printf("Quantity: ");
        scanf("%d", &order.items[i].quantity);
        getchar();

        printf("Price: ");
        scanf("%f", &order.items[i].price);
        getchar();
    }

    return order;
}

struct Order computeTotal(struct Order order) {
    order.totalAmount = 0.0;
    
    //bale items times price lang
    for (int i = 0; i < order.itemCount; i++) {
        order.totalAmount += order.items[i].quantity * order.items[i].price;
    }
    return order;
}

void viewOrders() {
    FILE *fptr = fopen("orders.txt", "r");
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

