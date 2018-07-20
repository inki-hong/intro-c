#include <stdio.h>

void swap(int* a, int* b);  // function declaration

int main() {
    int x = 0, y = 1;
    printf("Before swap x: %d y: %d \n", x, y);

    swap(&x, &y);
    printf("After  swap x: %d y: %d \n", x, y);
}

void swap(int* a, int* b) {  // function definition
    int temp = *b;
    *b = *a;
    *a = temp;
}
