#include <stdio.h>

int main() {
    int i = 12;
    i = 36;

    const int c = 12;
    // c = 36;  /* compile error */

    /**************************************/

    int* ip = &i;
    *ip = 24;

    const int* cp = &i;
    // *cp = 48;  /* compile error */

    int* ip2 = &c;  /* warning */
    *ip2 = 60;
    printf("%d \n", *ip2);

    /**************************************/

    int* const cp2 = &i;
    // cp2 = &c;  /* compile error */
}
