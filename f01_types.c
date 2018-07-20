#include <stdio.h>

int main() {
    printf("Integer data types in C \n");

    char ch = 'A';
    short sh = 100;
    int i = 3000;
    long el = 50000;

    printf("Char:  %c  \n", ch);
    printf("Short: %d  \n", sh);
    printf("Int:   %d  \n", i);
    printf("Long:  %ld \n", el);

    printf("Char as int: %d \n", ch);

    printf("----------------------------------------\n");

    float f = 1.414;
    double d = 3.141592;

    printf("Float: %f \n", f);
    printf("Double: %f \n", d);

    printf("----------------------------------------\n");
}
