
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 3;
    int b = 4;

    int* bPtr = &b;

    printf("%d\n", b);
    printf("%d\n", bPtr);
    printf("%d\n", *bPtr);

    *bPtr = 6;

    printf("%d\n", b);

    return 0;
}

