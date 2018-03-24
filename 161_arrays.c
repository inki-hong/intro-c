#include <stdio.h>

#define NUMBER_OF_DIGITS 10

int main() {
    long numbers[NUMBER_OF_DIGITS];
    for (int i = 0; i <= NUMBER_OF_DIGITS - 1; i++) {
        numbers[i] = 0;
    }
    long whitespaces = 0;
    long others = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if ('0' <= c && c <= '9') {
            numbers[c - '0']++;
        } else if (c == '\n' || c == '\t' || c == ' ') {
            whitespaces++;
        } else {
            others++;
        }
    }
    for (int i = 0; i <= NUMBER_OF_DIGITS - 1; i++) {
        printf("%d = %ld ", i, numbers[i]);
    }
    printf("whitespaces = %ld others = %ld\n", whitespaces, others);
}
