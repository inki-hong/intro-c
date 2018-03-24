#include <stdio.h>

int main() {
    int fahr, cels;
    int lower, upper;
    int step;

    lower = 20;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        cels = (5.0 / 9.0) * fahr - 32;
        printf("%d\t%d\n", fahr, cels);
        fahr += step;
    }
}
