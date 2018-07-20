#include <stdio.h>

int cube(int n);  // function declaration

int main() {
    int c = cube(4);

    printf("%d cubed: %d", 4, c);
}

int cube(int n) {  // function definition
    return n * n * n;
}
