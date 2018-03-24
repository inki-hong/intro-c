#include <stdio.h>

#define LOWER 20
#define UPPER 300
#define STEP 20

int main() {
    int fahr, cels;
    int lower, upper;
    int step;

    lower = LOWER;
    upper = UPPER;
    step = STEP;

    fahr = lower;
    while (fahr <= upper) {
        cels = (5.0 / 9.0) * fahr - 32;
        printf("%d\t%d\n", fahr, cels);
        fahr += step;
    }
}
