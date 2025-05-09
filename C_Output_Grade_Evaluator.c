#include <stdio.h>

int main() {
    int grade;

    printf("Enter your final grade: ");
    scanf("%d", &grade);

    if (grade >= 75) {
        printf("You have passed the subject! Congratulations!\n");
    } else {
        printf("You failed the subject. Work hard to get better marks next time.\n");
    }

    return 0;
}
