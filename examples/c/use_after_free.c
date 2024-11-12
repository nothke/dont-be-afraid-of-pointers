#include <stdio.h>
#include <stdlib.h>

int main() {
    void* myBlockOfMemory = malloc(64);

    int* intPtr = (int*)myBlockOfMemory;

    printf("%d\n", *intPtr);

    *intPtr = 666;

    printf("%d\n", *intPtr);

    free(myBlockOfMemory);

    printf("%d\n", *intPtr);

    printf("%d\n", intPtr[456]);

    return 0;
}