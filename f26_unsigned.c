#include <stdio.h>

int main() {
    int i = -100;
    unsigned int u = 100;  // or 100u
    size_t sz = 100;

    if (i < u) {
        printf("Of course \n");
    }
    if (i < sz) {
        printf("Of course \n");
    }

    /* WARNING - infinite loop
    for (size_t x = sizeof(int); x >= 0; x--) {
        printf("Infinite %u \n", x);
    }
    */

    /**************************************/

    int n = 2000000000 + 500000000;  // undefined
    printf("%d \n", n);
    unsigned z = 4294967295u + 100u;  // positive overflow
    printf("%u \n", z);
}
