#include <stdio.h>

void insertion_sort(char *str);

int main() {
    char buffer[100];     /* 영문 최대 99글자 */
    printf("Enter a word: ");
    scanf("%s", buffer);  /* 사용자 입력을 buffer 에 저장합니다 */

    char* user_word = buffer;
    insertion_sort(user_word);

    printf("Sorted: %s \n", user_word);

    return 0;
}

/*
 * TODO Insertion sort 알고리즘을 사용해 완성해 주세요
 * https://en.wikipedia.org/wiki/Insertion_sort
 *
 * 파라미터 str: C-string (0 으로 종료)
 *
 * str 이 알파벳 오름차순으로 정렬됩니다.
 * In-place change 로써 str 이 가리키는 메모리 블록이 변경됩니다
 */
void insertion_sort(char *str) {

}
