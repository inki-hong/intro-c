#include <stdio.h>

void speak(char* message, int how_many);

int main() {

    // Function pointers --------------------

    void (*say_hello)(char* greeting, int count);
    say_hello = speak;

    speak("Mic test", 2);
    say_hello("Hello!", 3);

    // Function pointer casting --------------------

    void (*fp)(void* vp, short c);
    fp = (void (*)(void* vp, short c)) speak;
    fp("Bye!", 2);
}

void speak(char* message, int how_many) {
    for (int i = 0; i < how_many; i++) {
        printf("%s \n", message);
    }
}
