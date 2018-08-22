#include <stdio.h>

double add(void* a, void* b, double (*fp)(void*, void*));
double iadd(int* a, int* b);
double dadd(double* a, double* b);

int main() {
    int x = 2, y = 4;
    double d1 = 3.3, d2 = 5.5;

    printf("%f \n", add(&x, &y, iadd));
    printf("%f \n", add(&d1, &d2, dadd));

    printf("%f \n", add(&x, &y, (double (*)(void*, void*)) iadd));
    printf("%f \n", add(&d1, &d2, (double (*)(void*, void*)) dadd));
}

double add(void* a, void* b, double (*fp)(void*, void*)) {
    return fp(a, b);
}

double iadd(int* a, int* b) {
    return *a + *b;
}

double dadd(double* a, double* b) {
    return *a + *b;
}
