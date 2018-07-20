#include <stdio.h>

int main() {
    int a = 42;
    int b = 55;
    if (a < b) {
        printf("B bigger \n");
    } else if (a > b) {
        printf("A bigger \n");
    } else {
        printf("Same \n");
    }

    printf("----------------------------------------\n");

    if (1) {
        printf("Hello 1 \n");
    }
    if (100) {
        printf("Hello 100 \n");
    }
    if (0) {
        printf("Hello 0 \n");
    }
    if (-1) {
        printf("Hello -1 \n");
    }

    printf("----------------------------------------\n");

    int x = 10;
    int y = 200;

    int max1;
    if (x > y) {
        max1 = x;
    } else {
        max1 = y;
    }
    printf("Max: %d \n", max1);

    int max2 = (x > y) ? x : y;
    printf("Max: %d \n", max2);

    printf("----------------------------------------\n");
}
