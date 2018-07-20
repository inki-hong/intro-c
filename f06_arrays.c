#include <stdio.h>

int main() {
    int scores[] = {50, 25, 75};

    for (int i = 0; i < 3; i++) {
        int current_score = scores[i];
        printf("Score: %d \n", current_score);
    }

    printf("----------------------------------------\n");

    int new_scores[5];
    new_scores[0] = 10;
    new_scores[4] = 50;

    for (int i = 0; i < 5; i++) {
        int current_score = new_scores[i];
        printf("New Score: %d \n", current_score);
    }

    printf("----------------------------------------\n");

    for (int i = 0; i < 5; i++) {
        new_scores[i] = (i + 1) * 10;
        printf("New Score: %d \n", new_scores[i]);
    }

    printf("----------------------------------------\n");

    printf("Size of char: %u byte(s) \n", sizeof(char));
    printf("Size of short: %u byte(s) \n", sizeof(short));
    printf("Size of int: %u byte(s) \n", sizeof(int));
    printf("Size of long: %u byte(s) \n", sizeof(long));

    for (int i = 0; i < sizeof(scores) / sizeof(int); i++) {
        int current_score = scores[i];
        printf("Score: %d \n", current_score);
    }
}
