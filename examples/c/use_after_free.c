#include <stdio.h>
#include <stdlib.h>

int main() {
    void* myBlockOfMemory = malloc(64);

    int* intPtr = (int*)myBlockOfMemory;

    printf("%d\n", *intPtr);

    int* nul = NULL;
    printf("%d\n", *nul);

    *intPtr = 666;

    printf("%d\n", *intPtr);

    free(myBlockOfMemory);

    printf("%d\n", *intPtr);

    printf("%d\n", intPtr[4562]);

    return 0;
}