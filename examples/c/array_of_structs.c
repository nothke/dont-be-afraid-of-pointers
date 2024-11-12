#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Coord;

int main() {
    Coord array[4];

    printf("%d, %d", array[0].x, array[0].y);

    return 0;
}