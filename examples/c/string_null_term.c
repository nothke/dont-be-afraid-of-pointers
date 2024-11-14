
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[4] = "zig";
    char s2[4] = "abc";
    char s3[] = "lsd";

    s2[6] = '\0';

    printf("\n%s, %i\n", s1, s1);
    printf("%s, %i\n", s2, s2);
    printf("%s, %i\n", s3, s3);

    return 0;
}