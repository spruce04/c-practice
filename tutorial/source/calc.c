//calc is slang for calculator btw
#include <stdio.h>
#include <stdlib.h>

int main() {
    double first;
    double second;

    printf("Enter the first value: ");
    scanf("%lf", &first);

    printf("Enter the second value: ");
    scanf("%lf", &second);

    printf("The result is %f\n", first+second);
}