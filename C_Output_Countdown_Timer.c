#include <stdio.h>
#include <unistd.h> 

int main() {
    int seconds;

    printf("Enter the number of seconds for the countdown: ");
    scanf("%d", &seconds);


    for (int i = seconds; i >= 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }

    printf("Time's Up!\n");
    return 0;
}
