#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calc() { //slang for calculator
    char operation[10];
    double first;
    double second;

    //get the input
    printf("Enter your desired operation (add, multiply, subtract, or divide): ");
    fgets(operation, 10, stdin);
    operation[strcspn(operation, "\n")] = '\0';  //get rid of \n
    printf("Enter the first desired number: ");
    scanf("%lf", &first);
    printf("Enter the second desired number: ");
    scanf("%lf", &second);

    //calculate depending on the operation
    if (strcmp(operation, "add") == 0) {
        return first + second;
    }
    else if (strcmp(operation, "subtract") == 0) {
        return first - second;
    }
    else if (strcmp(operation, "multiply") == 0) {
        return first * second;
    }
    else if (strcmp(operation, "divide") == 0) {
        return first / second;
    }
    else {
        printf("Operator %s is not recognised\n", operation);
        return 0;
    }
} 

int main() {
    double result = calc();
    printf("The answer is %f", result);
    return 0;
}