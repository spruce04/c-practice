#include <stdio.h>
#include <stdlib.h>

//#include <stdlib.h> is needed to use malloc, realloc etc.
//#include <stdio.h> is needed for input/output

//an array list that can store ints
struct IntList {
    int* list;
    int maxSize;
    int size;
};

//resizes the list by increasing maxSize
struct IntList resize(struct IntList paramList) {
    paramList.maxSize += 10;
    int* temp = realloc(paramList.list, paramList.maxSize * sizeof(int));
    if (temp == NULL) { //if there's an error
        printf("Memory allocation failed!\n");
        return paramList;
    }
    paramList.list = temp;
    return paramList;
}

//adds an integer to the list
struct IntList add(int toAdd, struct IntList paramList) {
    if(paramList.size >= paramList.maxSize) {
        paramList = resize(paramList);
    }
    paramList.list[paramList.size] = toAdd;
    paramList.size++;
    return paramList;
}

int main() {
    struct IntList testList;
    testList.list = malloc(10 * sizeof(int));
    if (testList.list == NULL) { //make sure malloc has been successful
        printf("Memory allocation failed!\n");
        return 1;
    }
    testList.maxSize = 10;
    testList.size = 0;

    testList = add(1, testList);

    free(testList.list); //free memory to avoid leaks
    return 0;
}