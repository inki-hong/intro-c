#include <stdio.h>

int main() {
    long cc = 0;
    int c;

    while ((c = getchar()) != EOF) {  // Ctrl + D for EOF
        cc++;
    }
    printf("%ld\n", cc);

    return 0;
}
