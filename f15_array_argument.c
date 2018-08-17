#include <stdio.h>

void func_1(int abc[]);
void func_2(int* abc);
void func_3(int* abc, int n);

int main() {
    int numbers[] = {2, 3, 5, 7, -1};
    printf("Size outside: %u bytes \n", sizeof(numbers));
    func_1(numbers);
    func_2(numbers);
    func_3(numbers, sizeof(numbers) / sizeof(int));
}

void func_1(int abc[]) {
    printf("Size inside: %u bytes \n", sizeof(abc));
}

void func_2(int* abc) {
    printf("Size inside: %u bytes \n", sizeof(abc));

    while (*abc > 0) {
        printf("%d \t", *abc);
        abc += 1;  // pointer arithmetic
    }
    printf("\n");
}

void func_3(int* abc, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d \t", abc[i]);
    }
    printf("\n");
}
