#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    long wc = 0;
    short in_or_out = OUT;
    int c;
    while ((c = getchar()) != EOF) {
        if ('a' <= c && c <= 'z' && in_or_out == OUT) {
            in_or_out = IN;
            wc++;
        } else if ((c < 'a' || 'z' < c) && in_or_out == IN) {
            in_or_out = OUT;
        }
    }
    printf("%ld\n", wc);
}
