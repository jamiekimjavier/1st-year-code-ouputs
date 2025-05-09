#include <stdio.h>

int main(void) {

    int activity, duration, result;
    
    printf("Enter details for 3 activities\n");

    do {
    for(int i=1; i<4; i++) {
    printf("Enter activity type %d\n", i );
    scanf("%d", &activity);

    printf("Enter duration in minutes\n");
    scanf("%d", &duration);

    
    if (activity == 1) {
      result = 5*duration;
      printf("Calories burned for Walking: %d\n" , result);
    } else if (activity == 2) {
        result = 10*duration;
      printf("Calories burned for Running: %d\n" , result);
    } else if (activity == 3) { 
        result = 8*duration;
      printf("Calories burned for Cycling: %d\n" , result);
    } else {
        printf("Invalid activity type. Please enter 1, 2 or 3.\n" ); 
        i--;
        
    }
    }
    
    
break;

} while (result > 0);



}

