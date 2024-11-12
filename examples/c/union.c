#include <stdio.h>
#include <stdlib.h>

typedef union {
    char c;
    int i;
    float f;
} Packet;

int main() {
    Packet packet;
    packet.i = 3;

    printf("%d", packet.i);
    printf("%f", packet.f);

    return 0;
}