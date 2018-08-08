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

    /****************************************/

    typedef struct coordinate {
        double x;
        double y;
    } Coordinate;

    Coordinate coord1;
    coord1.x = 1.5;
    coord1.y = 2.4;

    Coordinate* pc = &coord1;
    printf("x: %f \n", (*pc).x);
    printf("x: %f \n", pc->x);
}
