#include <stdio.h>
#include <stdlib.h>

int main() {
    void* myBlockOfMemory = malloc(64);

    int* intPtr = (int*)myBlockOfMemory;

    free(myBlockOfMemory);

    return 0;
}