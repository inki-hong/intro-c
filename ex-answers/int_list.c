#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* int 리스트를 나타냅니다.
 * 단 실제 int 데이터는 별도의 연속 메모리 블록에 저장되며,
 * 이 struct 는 해당 메모리에 대한 포인터만을 가지고 있습니다 */
typedef struct _int_list {
    int item_count;  /* 현재 아이템 개수 */
    int capacity;    /* 최대 개수 */
    int* items;      /* 실제 아이템이 저장된 메모리를 가리킴 */
} int_list;

/* TODO 하단 부분에 아래 함수들의 definition 을 완성해 주세요. */
int_list int_list_create(int initial_capacity);
short int_list_destroy(int_list* p_list);
short int_list_append(int_list* p_list, int item);
short int_list_insert(int_list* p_list, int item, int index);
int int_list_get(int_list* p_list, int index);
int int_list_index_of(int_list* p_list, int item);
short int_list_remove(int_list* p_list, int index);
short int_list_set(int_list* p_list, int index, int item);

/**********************************************************************************************************************/

/* int list 관련 함수를 테스트합니다. 출력 내용도 정확해야 하고 assert 도 에러없이 통과해야 합니다 */
int main() {
    printf("CREATE ---------------------------------------- \n");
    int_list list = int_list_create(2);

    printf("APPEND ---------------------------------------- \n");
    int numbers[] = {4, 8, 16, 32, 64};
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        int_list_append(&list, numbers[i]);
        printf("Element %d/%d: %d \n", i + 1, list.capacity, *(list.items + i));
    }
    assert(list.capacity == 8);

    printf("INSERT ---------------------------------------- \n");
    int a = 5, b = 3, c = 1;
    assert(int_list_insert(&list, a, -1) == -1);
    assert(int_list_insert(&list, a, 6) == -1);
    int_list_insert(&list, a, 2);
    int_list_insert(&list, b, 2);
    int_list_insert(&list, c, 2);
    for (int i = 0; i < list.item_count; i++) {
        printf("Element %d/%d: %d \n", i + 1, list.capacity, *(list.items + i));
    }

    printf("GET ---------------------------------------- \n");
    assert(int_list_get(&list, -1) == -1);
    assert(int_list_get(&list, 9) == -1);
    for (int i = 0; i < list.item_count; i++) {
        printf("Element %d/%d: %d \n", i + 1, list.capacity, int_list_get(&list, i));
    }

    printf("INDEX OF ---------------------------------------- \n");
    a = 16, b = -16;
    int a_index = int_list_index_of(&list, a);
    int b_index = int_list_index_of(&list, b);
    printf("%d is %d th item \n", a, a_index + 1);
    printf("%d is %d th item \n", b, b_index + 1);

    printf("REMOVE ---------------------------------------- \n");
    assert(int_list_remove(&list, -1) == -1);
    assert(int_list_remove(&list, 9) == -1);
    int_list_remove(&list, int_list_index_of(&list, a));
    for (int i = 0; i < list.item_count; i++) {
        printf("Element %d/%d: %d \n", i + 1, list.capacity, int_list_get(&list, i));
    }

    printf("SET ---------------------------------------- \n");
    a = 61;
    assert(int_list_set(&list, -1, a) == -1);
    assert(int_list_set(&list, 9, a) == -1);
    int_list_set(&list, 6, a);
    for (int i = 0; i < list.item_count; i++) {
        printf("Element %d/%d: %d \n", i + 1, list.capacity, int_list_get(&list, i));
    }

    printf("DESTROY ---------------------------------------- \n");
    int_list_destroy(&list);

    return 0;
}

/**********************************************************************************************************************/

/* int list 를 생성하고 리턴합니다. initial_capacity 만큼 초기 메모리를 할당합니다 */
int_list int_list_create(int initial_capacity) {
    int_list list;
    list.item_count = 0;
    list.items = malloc(sizeof(int) * initial_capacity);
    list.capacity = initial_capacity;
    return list;
}

/* TODO 아래 7개 함수를 완성해 주세요.
 * 모든 index 는 0 부터입니다.
 * 필요에 따라 malloc, free, realloc 기능을 사용하여 메모리를 직접 조절해야 합니다.
 * 특히 메모리가 찼을 경우 기존 capacity 의 2배가 되도록 메모리가 증가합니다.
 * int list 의 item_count, capacity 가 항상 정확한 값을 유지하도록 해야 하며,
 * items 가 가리키는 메모리 영역과의 일관성 또한 유지되어야 합니다 */

/* 주어진 int list 내에 동적으로 할당된 메모리를 회수합니다. 성공시 0, 실패시 -1 을 리턴합니다 */
short int_list_destroy(int_list* p_list) {
    if (p_list == NULL) {
        return -1;
    }
    p_list->item_count = 0;
    p_list->capacity = 0;
    free(p_list->items);
    return 0;
}

void _double_capacity(int_list* p_list) {
    int* new_space = malloc(p_list->item_count * sizeof(int) * 2);
    for (int i = 0; i < p_list->item_count; i++) {
        new_space[i] = (p_list->items)[i];
    }
    free(p_list->items);
    p_list->items = new_space;
    p_list->capacity *= 2;
}

/* p_list 의 끝에 item 을 추가합니다.
 * capacity 가 찼을 경우 자동으로 메모리를 2배로 추가할당해야 합니다. <- 중요!
 * 성공시 0, 실패시 -1 을 리턴합니다 */
short int_list_append(int_list* p_list, int item) {
    if (p_list == NULL) {
        return -1;
    }
    if (p_list->capacity == p_list->item_count) {
        _double_capacity(p_list);
    }
    p_list->items[p_list->item_count] = item;
    (p_list->item_count)++;
    return 0;
}

/* index 지점에 item 을 추가합니다.
 * capacity 가 찼을 경우 자동으로 메모리를 2배로 추가할당해야 합니다. <- 중요!
 * 성공시 0, 실패시 -1 을 리턴합니다 */
short int_list_insert(int_list* p_list, int item, int index) {
    if (index < 0 || index > p_list->item_count) {
        return -1;
    }
    if (p_list->capacity == p_list->item_count) {
        _double_capacity(p_list);
    }
    for (int i = p_list->item_count - 1; i >= index; i--) {
        (p_list->items)[i + 1] = (p_list->items)[i];
    }
    (p_list->items)[index] = item;
    (p_list->item_count)++;
    return 0;
}

/* index 번째 아이템을 리턴합니다. index 가 잘못되었을 경우 -1 을 리턴합니다 */
int int_list_get(int_list* p_list, int index) {
    if (index < 0 || index >= p_list->item_count) {
        return -1;
    }
    return (p_list->items)[index];
}

/* item 이 몇번째 index 에 있는지를 리턴합니다.
 * 2개 이상 존재할 경우에는 첫번째 index 를 리턴합니다.
 * item 이 존재하지 않을 경우 -1 을 리턴합니다 */
int int_list_index_of(int_list* p_list, int item) {
    for (int i = 0; i < p_list->item_count; i++) {
        if ((p_list->items)[i] == item) {
            return i;
        }
    }
    return -1;
}

/* p_list 에서 index 번째 아이템을 제거합니다.
 * 뒷부분의 아이템들을 이동시켜 중간에 빈칸이 없도록 해야 합니다.
 * 성공시 0, 실패시 -1 을 리턴합니다 */
short int_list_remove(int_list* p_list, int index) {
    if (index < 0 || index >= p_list->item_count) {
        return -1;
    }
    for (int i = index + 1; i < p_list->item_count; i++) {
        (p_list->items)[i - 1] = (p_list->items)[i];
    }
    (p_list->item_count)--;
    return 0;
}

/* index 번째를 item 으로 설정합니다. 성공시 0, 실패시 -1 을 리턴합니다 */
short int_list_set(int_list* p_list, int index, int item) {
    if (index < 0 || index >= p_list->item_count) {
        return -1;
    }
    p_list->items[index] = item;
    return 0;
}
