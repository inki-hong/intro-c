#include <stdio.h>
#include <string.h>

void my_strcat(char* to, char* from);

int main() {
    char buffer[1000];
    strcpy(buffer, "----------------------------------------");
    strcpy(buffer, "strawberry");
    strcat(buffer, " banana");
    printf("Buffer %s \n", buffer);

    my_strcat(buffer, " juice");
    printf("Buffer %s \n", buffer);
}

void my_strcat(char* to, char* from) {
    while (*to != '\0') {
        to++;
    }
    while (*from != '\0') {
        *to = *from;
        to++;
        from++;
    }
    *to = '\0';
}
