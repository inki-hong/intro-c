#include <stdio.h>

int main() {
    struct fraction {
        int numerator;
        int denominator;
    };

    struct fraction frac1;
    frac1.numerator = 5;
    frac1.denominator = 22;

    typedef struct fraction Fraction;

    Fraction frac2;
    frac2.numerator = 6;
    frac2.denominator = 21;
}
