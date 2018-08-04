#include <stdio.h>

int main() {
    char* charPtr;
    int* intPtr;

    printf("Size of char pointer: %u byte(s) \n", sizeof(charPtr));
    printf("Size of int pointer: %u byte(s) \n", sizeof(intPtr));

    printf("----------------------------------------\n");

    int i = 42;
    int* ptr = &i;

    printf("ptr: %p \n", ptr);
    printf("*ptr: %d \n", *ptr);
    printf("i: %d \n", i);
    printf("&i: %p \n", &i);

    printf("----------------------------------------\n");

    *ptr = 13;

    printf("ptr: %p \n", ptr);
    printf("*ptr: %d \n", *ptr);
    printf("i: %d \n", i);
    printf("&i: %p \n", &i);

    printf("----------------------------------------\n");

    int* uninit;

    printf("uninit: %p \n", uninit);
//    printf("*uninit: %d \n", *uninit);

    printf("----------------------------------------\n");

    int x = 1234;
    int* px = &x;
    int** ppx = &px;
    printf("x: %d \n", x);
    printf("px: %p \n", px);
    printf("ppx: %p \n", ppx);
    printf("&x: %p \n", &x);
//    printf("&&x: %p \n", &&x);
    printf("*px: %i \n", *px);
//    printf("**px: %i \n", **px);
    printf("**ppx: %i \n", **ppx);
}
