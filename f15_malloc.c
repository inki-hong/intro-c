#include <stdio.h>
#include <stdlib.h>

int main() {
    char* buffer_1;
    buffer_1 = "apple";
    printf("Contents: %s \n", buffer_1);

    char* buffer_2;
    buffer_2 = malloc(sizeof(char) * (6 + 1));
    buffer_2[0] = 'b';
    buffer_2[1] = 'a';
    buffer_2[2] = 'n';
    buffer_2[3] = 'a';
    buffer_2[4] = 'n';
    buffer_2[5] = 'a';
    buffer_2[6] = 0;
    printf("Contents: %s \n", buffer_2);

    printf("----------------------------------------\n");

    int* numbers[3];
    numbers[0] = malloc(sizeof(int) * 3);
    numbers[1] = malloc(sizeof(int) * 2);
    numbers[2] = malloc(sizeof(int) * 4);

    free(buffer_2);
    free(numbers[0]);
    free(numbers[1]);
    free(numbers[2]);
}
