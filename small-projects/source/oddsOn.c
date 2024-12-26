#include <stdio.h>
#include <stdlib.h>
#include <time.h>//to use random number generator
#include <stdbool.h>//to use true/false
#include <string.h> // Include this header for strcspn

//function to get a random number
int getRandom(int max) {
    srand(time(0));
    int randomNum = rand() % (max);
    printf("The number selected was %d\n", randomNum+1);
    return randomNum+1;
}

//function to play the game
char* odds(int max, int chosen, char* task) {
    char* returnString = (char*)malloc(200);
    if (returnString == NULL) {
        return "Couldn't allocate memory";
    }

    int rNum = getRandom(max);
    if (rNum == chosen) {
        snprintf(returnString, 200, "Numbers match... time to %s...", task);
    }
    else {
        snprintf(returnString, 200, "Lucky...");
    }
    return returnString;
}

int main() {
    while(true) {
        char task[200];
        int max;
        int chosen;
        printf("Enter either a task or STOP to end the program: ");
        fgets(task, sizeof(task), stdin);
        task[strcspn(task, "\n")] = '\0';//removes the newline character

        if(strcmp("STOP", &task) == 0) {
            printf("bye :(\n");
            break;
        }

        printf("Choose the odds: ");
        scanf("%d", &max);
        printf("Choose your number: ");
        scanf("%d", &chosen);
        getchar();//clear the \n

        char* result = odds(max, chosen, task);
        printf("%s\n", result);
        }
    return 0;
}