#include <stdio.h>
#include <stdlib.h>

int main() {
    char array[4] = {1, 2, 3, 4};

    array[0] = 13;

    printf("%d", array);

    return 0;
}