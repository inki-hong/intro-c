#include <stdio.h>

int main() {
    int x;

    x = 5;
    while (x > 0) {
        printf("While x: %d \n", x);
        x = x - 1;  // x -= 1
    }

    printf("----------------------------------------\n");

    x = 5;
    do {
        printf("Do-while x: %d \n", x);
        x = x - 1;  // x -= 1
    } while (x > 0);

    printf("----------------------------------------\n");

    for (int i = 0; i < 5; i++) {
        printf("For x: %d x^2: %d \n", i, i*i);
    }
}
