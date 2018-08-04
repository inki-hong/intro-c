#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        printf("For x: %d x^2: %d \n", i, i*i);
    }

    for (int i = 11; i <= 20; i++) {
        if (i % 3 == 0) {
            printf("%d \t Y \n", i);
        } else {
            printf("%d \t N \n", i);
        }
    }

    int count = 0;
    for (int i = 201; i <= 300; i++) {
        if (i % 7 == 0) {
            count++;
        }
    }
    printf("Count: %d \n", count);

    int total = 0;
    for (int i = 301; i <= 400; i++) {
        total = total + i;  // total += i
    }
    printf("Total: %d \n", total);

    int sum = 0;
    for (int i = 401; i <= 500; i++) {
        if (i % 13 == 0) {
            sum += i;
        }
    }
    printf("Partial Sum: %d \n", sum);

    printf("----------------------------------------\n");

    int x;
    x = 5;
    while (x > 0) {
        printf("While x: %d \n", x);
        x = x - 1;  // x -= 1
    }

    int wsum = 0;
    int i = 401;
    while (i <= 500) {
        if (i % 13 == 0) {
            wsum += i;
        }
        i++;
    }
    printf("Partial Sum (while): %d \n", wsum);

    printf("----------------------------------------\n");

    int y;
    y = 5;
    do {
        printf("Do-while y: %d \n", y);
        y = y - 1;  // x -= 1
    } while (y > 0);
}
