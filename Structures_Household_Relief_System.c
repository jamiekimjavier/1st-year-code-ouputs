#include <stdio.h>
#include <stdlib.h>

struct Household {
    char headName[100];
    int members;
    int purok;
    int reliefPack;
};


void displayHousehold(struct Household households[], int size);
int sumReliefPacks(struct Household households[], int size);

int main (void) {
    int size;

    printf("\n============================================="
            "\n|  BARANGAY RELIEF DISTRIBUTION TRACKER |\n"
            "=============================================\n");

    printf("\n> Enter number of households to record: ");
    scanf("%d", &size);

    struct Household *households = (struct Household *)malloc(size * sizeof(struct Household));
    
    if (households == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    

    printf("\n> Enter details for %d households:\n", size);
        for (int i = 0; i < size; i++) {
            printf("\n======= Household #%d: ======= \n", i + 1);
            printf("Name of Head of Household: ");
            scanf(" %[^\n]", households[i].headName);
            printf("Number of Members: ");
            scanf("%d", &households[i].members);
            printf("Purok: ");
            scanf("%d", &households[i].purok);
            printf("Number of Relief Packs: ");
            scanf("%d", &households[i].reliefPack);
        }

    printf("\n======= Relief Distribution List: =======\n");
    displayHousehold(households, size);

    printf("\n======= Total Number of Relief packs: %d =======", sumReliefPacks(households, size));

    free(households);

    return 0;
}

void displayHousehold(struct Household households[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\n=======Household #%d=======\n", i + 1);
        printf("Head: %s\n", households[i].headName);
        printf("Members: %d\n", households[i].members);
        printf("Purok: %d\n", households[i].purok);
        printf("Relief Packs: %d\n", households[i].reliefPack);
    }
}

int sumReliefPacks(struct Household households[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
    sum += households[i].reliefPack;
    }

    return sum;
    
}
