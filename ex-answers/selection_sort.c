#include <stdio.h>

int my_strlen(char* str);
void selection_sort(char* str);

int main() {
    char buffer[100];     /* 영문 최대 99글자 */
    printf("Enter a word: ");
    scanf("%s", buffer);  /* 사용자 입력을 buffer 에 저장합니다 */

    char* user_word = buffer;
    selection_sort(user_word);

    printf("Sorted: %s \n", user_word);

    return 0;
}

int my_strlen(char* str) {
    char* ptr = str;  // aliasing
    int len = 0;
    while (*ptr != 0) {
        len = len + 1;
        ptr = ptr + 1;  // pointer + integer = pointer arithmetic
    }
    return len;
}

/*
 * TODO Selection sort 알고리즘을 사용해 완성해 주세요
 * https://en.wikipedia.org/wiki/Selection_sort
 *
 * 파라미터 str: C-string (0 으로 종료)
 *
 * str 이 알파벳 오름차순으로 정렬됩니다.
 * In-place change 로써 str 이 가리키는 메모리 블록이 변경됩니다
 */
void selection_sort(char* str) {
    int length = my_strlen(str);

    for (int a = 0; a < length - 1; a++) {

        char min = 127;
        int min_pos = 0;
        for (int b = a; b < length; b++) {
            if (str[b] < min) {
                min = str[b];
                min_pos = b;
            }
        }

        char temp = str[a];
        str[a] = str[min_pos];
        str[min_pos] = temp;
    }
}
