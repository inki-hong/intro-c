#include <stdio.h>

int main() {
    char* charPtr = "apple";  // string literal (string constant)
    char charArr[] = "banana";

    printf("char pointer: %s \n", charPtr);
    printf("char array: %s \n", charArr);

    printf("----------------------------------------\n");

    unsigned sz = sizeof(charArr) / sizeof(char);

    printf("Size of char array: %u \n", sz);

    printf("----------------------------------------\n");

    char unknownString[11];
    for (int i = 0; i < 10; i++) {
        unknownString[i] = 'a';
    }
    unknownString[10] = 0;  // trailing zero
    printf("unknown string: %s \n", unknownString);

    printf("----------------------------------------\n");

    char undelimitedString[11];
    for (int i = 0; i < 10; i++) {
        undelimitedString[i] = 'a';
    }
    printf("undelimited string: %s \n", undelimitedString);
}
