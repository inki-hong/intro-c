#include <stdio.h>

#include "tmp.h"

extern x;

int main() {
    printf("Hello! %d \n", x);

    speak("Nice to meet you", 3);
}
