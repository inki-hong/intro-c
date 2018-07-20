#include <stdio.h>

double gcube(void* number, double (*fp)(void* vp));
double icube(int* n);
double dcube(double* d);

int main() {
    double (*my_cube)(int* n);
    my_cube = icube;

    int x = 5;

    double y = icube(&x);
    printf("%d %f \n", x, y);

    y = my_cube(&x);
    printf("%d %f \n", x, y);

    /**************************************/

    double (*generic_cube)(void* vp);

    /**************************************/

    int i = 5;
    double d = 6.2;

    double c1 = gcube(&i, icube);
    double c2 = gcube(&d, dcube);

    printf("%f %f \n", c1, c2);
}

double gcube(void* number, double (*fp)(void* vp)) {
    return fp(number);
}

double icube(int* n) {
    return *n * *n * *n;
}

double dcube(double* d) {
    return *d * *d * *d;
}
