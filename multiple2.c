#include <stdio.h>

int x = 42;  // global variable

void speak(char* message, int how_many) {
    for (int i = 0; i < how_many; i++) {
        printf("%s \n", message);
    }
}
