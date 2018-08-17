#include <stdio.h>

void func_1(char* abc[], int n);
void func_2(char** abc, int n);

int main() {
    char* words[] = {"apple", "orange", "banana", "strawberry"};
    func_1(words, 3);
    func_2(words, sizeof(words) / sizeof(char*));
}

void func_1(char* abc[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s \n", abc[i]);
        // printf("%s \n", *(abc + i));
        if (abc[i][0] == 'a' || abc[i][0] == 'o') {
            printf("VOWEL \n");
        }
    }
}

void func_2(char** abc, int n) {
    for (int i = 0; i < n; i++) {
        // printf("%s \n", abc[i]);
        printf("%s \n", *(abc + i));
        if (**(abc + i) == 'a' || **(abc + i) == 'o') {
            printf("VOWEL \n");
        }
    }
}
