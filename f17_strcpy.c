#include <stdio.h>
#include <string.h>

void my_strcpy(char* to, char* from);

int main () {
    char buf[100];
    strcpy(buf, "hello, world");
    printf("Buffer: %s \n", buf);
    my_strcpy(buf, "hello, world");
    printf("Buffer: %s \n", buf);
}

void my_strcpy(char* to, char* from) {
    while (*from != 0) {
        *to = *from;
        to++;
        from++;
    }
}
