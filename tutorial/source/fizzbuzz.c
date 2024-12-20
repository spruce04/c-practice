#include <stdio.h>
#include <stdlib.h>

const char* fizzbuzz(int num) {
    if (num % 3 == 0 && num % 5 == 0) {
        return "fizzbuzz";
    }
    else if (num % 3 == 0) {
        return "fizz";
    }
    else if (num % 5 == 0) {
        return "buzz";
    }
    else {
        return "";
    }
}

int main() {
    int chosen;
    printf("Enter a number: ");
    scanf("%d", &chosen);
    const char* result = fizzbuzz(chosen);
    printf("%d %s\n", chosen, result);

    return 0;
}