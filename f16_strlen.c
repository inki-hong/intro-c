#include <stdio.h>
#include <string.h>

int my_strlen(char* str);

int main () {
    int len = strlen("hello, world");
    printf("Length of \"hello, world\" is %d \n", len);
    len = my_strlen("hello, world");
    printf("Length of \"hello, world\" is %d \n", len);
}

int my_strlen(char* str) {
    char* ptr = str;  // aliasing
    int len = 0;
    while (*ptr != 0) {
        len = len + 1;
        ptr = ptr + 1;  // pointer + integer = pointer arithmetic
    }
    return len;
}
