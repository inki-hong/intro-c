#include <stdio.h>
#include <string.h>

int main() {
    char* src = "apple";
    char dst[50];

    strcpy(dst, "strawberry");
    printf("Before: %s \n", dst);

    memcpy(dst, src, 5);
    printf("After: %s \n", dst);

    memcpy(dst, src, 5 + 1);
    printf("After: %s \n", dst);
}
