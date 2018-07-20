#include <stdio.h>

int main() {
    // This is a single-line comment.

    /*
     * This is a multi-line comment.
     */

    int a = 42;
    printf("a: %d \n", a);

    int b;
    b = 4242;
    printf("b: %d \n", b);

    int ab;
    printf("ab: %d \n", ab);

    printf("----------------------------------------\n");

    int ii = 321;
    char cc = ii;
    printf("cc: %c \n", cc);
    printf("cc: %d \n", cc);

    printf("----------------------------------------\n");

    int score = 10;
    score = (score / 20) * 100;
    printf("score: %d \n", score);

    score = 10;
    score = (score / 20.0) * 100;
    printf("correct score: %d \n", score);

    score = 10;
    score = (score / (double) 20) * 100;
    printf("correct score: %d \n", score);

    score = 10;
    score = (int) ((score / (double) 20) * 100);
    printf("correct score: %d \n", score);

    printf("----------------------------------------\n");
}
