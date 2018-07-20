#include <stdio.h>

int main() {
    char c1 = 3;
    char c2 = 5;
    char bit_and = c1 & c2;
    char bit_or = c1 | c2;
    printf("bit-wise AND: %d \n", bit_and);
    printf("bit-wise OR: %d \n", bit_or);

    printf("----------------------------------------\n");

    char bit_xor = c1 ^ c2;
    char bit_not = ~c1;
    printf("bit-wise XOR: %d \n", bit_xor);
    printf("bit-wise NOT: %d \n", bit_not);

    printf("----------------------------------------\n");

    char bit_left_shift = c1 << 2;
    char bit_right_shift = c1 >> 2;
    printf("bit-wise left shift: %d \n", bit_left_shift);
    printf("bit-wise right shift: %d \n", bit_right_shift);

    printf("----------------------------------------\n");
}
