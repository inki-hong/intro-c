#include <stdio.h>

int main () {
    char* cp = "apple";
    printf("Fruit: %s \n", cp);

    void* vp;
    vp = cp;

    char* cp2 = vp;
    printf("Fruit: %s \n", cp2);

    int* ip = vp;
    printf("Fruit: %d \n", *ip);
}
