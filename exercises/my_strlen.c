#include <stdio.h>
#include <string.h>  /* strlen 표준 라이브러리 버전 */
#include <assert.h>  /* assert 기능 */

int my_strlen(char* str);

int main() {
    char buffer[100];            /* 영문 최대 99글자 */
    printf("Enter a string: ");
    scanf("%s", buffer);         /* 사용자 입력을 buffer 에 저장합니다 */

    char* user_str = buffer;
    int len_1 = (int) strlen(user_str);
    int len_2 = my_strlen(user_str);

    printf("Length: %d %d \n", len_1, len_2);
    assert(len_1 == len_2);  /* 여기서 에러가 나지 않아야 합니다 */

    return 0;
}

/*
 * TODO 완성해 주세요
 *
 * 파라미터 str: C-string (0 으로 종료)
 * 리턴 값: str 의 길이 (0 을 제외한 글자 수)
 */
int my_strlen(char* str) {
    return -1;
}
