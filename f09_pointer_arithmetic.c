#include <stdio.h>

int main() {
    int scores[] = {50, 25, 75};

    printf("scores: %p \n", scores);

    for (int i = 0; i < 3; i++) {
        int current_score = scores[i];
        printf("scores[%d]: %d \n", i, current_score);
    }

    printf("----------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("scores + %d: %p \n", i, scores + i);
        int current_score = *(scores + i);
        printf("*(scores + %d): %d \n", i, current_score);
    }
}
