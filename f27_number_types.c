#include <stdio.h>

int main() {
    int d = 42;        // decimal
    int b = 0b101010;  // binary
    int o = 052;       // octal
    int h = 0x2A;      // hexadecimal
    printf("%d %d %d %d\n", d, b, o, h);

    // integer types
    printf("sizeof(char): %u\n",        sizeof(char));
    printf("sizeof(short): %u\n",       sizeof(short));
    printf("sizeof(int): %u\n",         sizeof(int));
    printf("sizeof(long): %u\n",        sizeof(long));
    printf("sizeof(long long): %u\n",   sizeof(long long));

    // floating point types
    printf("sizeof(float): %u\n",       sizeof(float));
    printf("sizeof(double): %u\n",      sizeof(double));
    printf("sizeof(long double): %u\n", sizeof(long double));

    return 0;
}
