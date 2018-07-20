#include <stdio.h>

int main() {
    int numbers_1[] = {2, 3, 5, 7};
    for (int i = 0; i < sizeof(numbers_1) / sizeof(int); i++) {
        printf("Number %d: %d \n", i, numbers_1[i]);
    }

    printf("----------------------------------------\n");

    int numbers_2[][3] = {{2, 3, 5}, {7, 11, 13}};  // only first dim can be empty
    for (int i = 0; i < sizeof(numbers_2) / sizeof(numbers_2[0]); i++) {
        for (int j = 0; j < sizeof(numbers_2[0]) / sizeof(int); j++) {
            printf("Number %d, %d: %d \n", i, j, numbers_2[i][j]);
        }
    }

    printf("----------------------------------------\n");

    char* words[] = {"apple", "orange", "banana"};
    for (int a = 0; a < sizeof(words) / sizeof(words[0]); a++) {
        printf("Word %d: %s \n", a, words[a]);
    }
}
