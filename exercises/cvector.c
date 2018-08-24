#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvector.h"

/*
 * int_list 의 generic version 을 구현하는 것이 목표입니다.
 * Generic version 이므로 모든 아이템들이 void pointer 로만 전달되는 것 유의해 주세요.
 * 모든 index 는 0 부터입니다.
 * 필요에 따라 malloc, free, realloc 기능을 사용하여 메모리를 직접 조절해야 합니다.
 * int_list 와 마찬가지로 메모리가 찼을 경우 기존 capacity 의 2배가 되도록 메모리가 증가해야 합니다.
 * 또한 generic version 이므로 int_list 와는 달리 단순한 아이템 복사가 되지 않습니다.
 * 아이템 복사는 memcpy 기능을 활용해야 합니다.
 * cvector structure 내 nelems 와 capacity 가 항상 정확한 값을 유지하도록 해야 하며,
 * elems 가 가리키는 메모리 영역과의 일관성 또한 유지되어야 합니다.
 *
 * 실행시켰을 때 출력 내용도 정확해야 하고 assert 도 에러없이 통과해야 합니다.
 * 아래 내용도 참고하세요.
 *
 * https://web.stanford.edu/class/archive/cs/cs107/cs107.1166/assign3/#implementation-details
 */

cvector* cvec_create(size_t elemsz, int capacity_hint) {
    cvector* pcv = malloc(sizeof(cvector));
    pcv->elemsz = elemsz;
    pcv->nelems = 0;
    pcv->elems = malloc(elemsz * capacity_hint);
    pcv->capacity = capacity_hint;
    return pcv;
}

void cvec_destroy(cvector* pcv) {
    pcv->nelems = 0;
    pcv->capacity = 0;
    free(pcv->elems);
}

/* TODO 하단 부분에 아래 함수들의 definition 을 완성해 주세요. */

int cvec_append(cvector* pcv, void* elem) {
    // TODO implementation
    return true;
}

int cvec_insert(cvector* pcv, void* elem, int index) {
    // TODO implementation
    return true;
}

void* cvec_get(cvector* pcv, int index) {
    // TODO implementation
    return NULL;
}

int cvec_index_of(cvector* pcv, void* elem) {
    // TODO implementation
    return -1;
}

int cvec_remove(cvector* pcv, int index) {
    // TODO implementation
    return true;
}

int cvec_set(cvector* pcv, int index, void* elem) {
    // TODO implementation
    return true;
}

void cvec_sort(cvector* pcv, int (*cmp)(const void*, const void*)) {
    qsort(pcv->elems, (unsigned) pcv->nelems, pcv->elemsz, cmp);
}

int cmp_int(const int* a, const int* b) {
    if (*a > *b) {
        return 1;
    } else if (*a < *b) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    cvector* pcv = cvec_create(sizeof(int), 2);

    int integers[] = {4, 8, 16, 32, 64};
    for (int i = 0; i < sizeof(integers)/sizeof(int); i++) {
        cvec_append(pcv, &integers[i]);
        printf("Element %d/%d: %d\n", i+1, pcv->capacity, *((int*) pcv->elems + i));
    }
    printf("----------------------------------------\n");

    int a = 5, b = 3, c = 1;
    assert(cvec_insert(pcv, &a, -1) == false);
    assert(cvec_insert(pcv, &a, 6) == false);
    cvec_insert(pcv, &a, 5);
    cvec_insert(pcv, &b, 5);
    cvec_insert(pcv, &c, 5);
    for (int i = 0; i < pcv->nelems; i++) {
        printf("Element %d/%d: %d\n", i+1, pcv->capacity, *((int*) pcv->elems + i));
    }
    printf("----------------------------------------\n");

    assert(cvec_get(pcv, -1) == NULL);
    assert(cvec_get(pcv, 9) == NULL);
    for (int i = 0; i < pcv->nelems; i++) {
        printf("Element %d/%d: %d\n", i+1, pcv->capacity, *((int*) cvec_get(pcv, i)));
    }
    printf("----------------------------------------\n");

    a = 16, b = -16;
    int a_index = cvec_index_of(pcv, &a);
    int b_index = cvec_index_of(pcv, &b);
    printf("%d is %d th item\n", a, a_index + 1);
    printf("%d is %d th item\n", b, b_index + 1);
    printf("----------------------------------------\n");

    assert(cvec_remove(pcv, -1) == false);
    assert(cvec_remove(pcv, 9) == false);
    cvec_remove(pcv, cvec_index_of(pcv, & a));
    for (int i = 0; i < pcv->nelems; i++) {
        printf("Element %d/%d: %d\n", i+1, pcv->capacity, *((int*) cvec_get(pcv, i)));
    }
    printf("----------------------------------------\n");

    a = 61;
    assert(cvec_set(pcv, -1, &a) == false);
    assert(cvec_set(pcv, 9, &a) == false);
    cvec_set(pcv, 6, &a);
    for (int i = 0; i < pcv->nelems; i++) {
        printf("Element %d/%d: %d\n", i+1, pcv->capacity, *((int*) cvec_get(pcv, i)));
    }
    printf("----------------------------------------\n");

    cvec_sort(pcv, (int (*) (const void*, const void*)) cmp_int);
    for (int i = 0; i < pcv->nelems; i++) {
        printf("Element %d/%d: %d\n", i+1, pcv->capacity, *((int*) cvec_get(pcv, i)));
    }

    cvec_destroy(pcv);
    free(pcv);
    return 0;
}
