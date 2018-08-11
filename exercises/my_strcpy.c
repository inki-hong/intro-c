#include <stdio.h>
#include <string.h>  /* strcpy 표준 라이브러리 버전 */
#include <assert.h>  /* assert 기능 */

void my_strcpy(char* to, char* from);

int main() {
    char from_buf[100];            /* 영문 최대 99글자 */
    char to_buf_1[100];            /* 영문 최대 99글자 */
    char to_buf_2[100];            /* 영문 최대 99글자 */
    printf("Enter a string: ");
    scanf("%s", from_buf);         /* 사용자 입력을 from_buf 에 저장합니다 */

    strcpy(to_buf_1, from_buf);
    my_strcpy(to_buf_2, from_buf);

    printf("Copy: %s %s \n", to_buf_1, to_buf_2);
    assert(strcmp(to_buf_1, to_buf_2) == 0);  /* 여기서 에러가 나지 않아야 합니다 */

    return 0;
}

/*
 * TODO 완성해 주세요
 *
 * 파라미터 to: C-string (0 으로 종료)
 * 파라미터 from: C-string (0 으로 종료)
 *
 * from 의 내용을 to 로 복사합니다.
 * 이 때, to 에는 충분한 메모리가 할당되어 있다고 가정합니다
 */
void my_strcpy(char* to, char* from) {

}
