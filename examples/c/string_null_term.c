
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[4] = "abc";
    char s2[4] = "abc";
    char s3[] = "abc";

    s1[3] = 'd';

    printf("%s, %i\n", s1, s1);
    printf("%s, %i\n", s2, s2);
    printf("%s, %i\n", s3, s3);

    return 0;
}