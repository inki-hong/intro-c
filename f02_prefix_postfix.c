#include <stdio.h>

int main() {
    int a = 42;
    printf("1: %d \n", a);

    a = a + 2;
    printf("2: %d \n", a);

    a += 2;
    printf("3: %d \n", a);

    a += 1;
    printf("4: %d \n", a);

    ++a;
    printf("5: %d \n", a);

    printf("----------------------------------------\n");

    ++a;  // prefix increment, --a prefix decrement
    printf("6: %d \n", a);

    a++;  // postfix increment, a-- postfix decrement
    printf("7: %d \n", a);

    printf("----------------------------------------\n");

    printf("8: %d \n", ++a);
    printf("9: %d \n", a);
    printf("10: %d \n", a++);
    printf("11: %d \n", a);
}
