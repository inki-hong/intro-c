#include <stdio.h>

void add(void* a, void* b, void* result, void (*fp)(void*, void*, void*));
void iadd(int* a, int* b, int* result);
void dadd(double* a, double* b, double* result);

int main() {
    int x = 2, y = 4, r1;
    double d1 = 3.3, d2 = 5.5, r2;

    add(&x, &y, &r1, iadd);
    add(&d1, &d2, &r2, dadd);

    printf("%d \n", r1);
    printf("%f \n", r2);
}

void add(void* a, void* b, void* result, void (*fp)(void*, void*, void*)) {
    fp(a, b, result);
}

void iadd(int* a, int* b, int* result) {
    *result = *a + *b;
}

void dadd(double* a, double* b, double* result) {
    *result = *a + *b;
}
