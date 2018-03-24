#include <stdio.h>

int main() {
    int c = 0;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
