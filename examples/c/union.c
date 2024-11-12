#include <stdio.h>
#include <stdlib.h>

typedef union {
    char c;
    int i;
    float f;
} Packet;

int main() {
    Packet packet;
    packet.i = 666;

    printf("\n%d\n", packet.i);
    printf("%f\n", packet.f);


    printf("%i\n", &packet.i);
    printf("%i\n", &packet.f);


    return 0;
}