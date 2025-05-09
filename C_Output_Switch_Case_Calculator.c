#include <stdio.h>

int main() {
    double number1, number2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &number1);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%lf", &number2);

    switch (operator) {
        case '+':
            result = number1 + number2;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = number1 - number2;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = number1 * number2;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (number2 != 0) {
                result = number1 / number2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator use +, -, *, or /. \n");
    }

    return 0;
}
