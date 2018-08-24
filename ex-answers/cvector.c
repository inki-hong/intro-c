#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvector.h"

void _cvec_increase_capacity(cvector* pcv) {
  void* new_space = malloc(pcv->elemsz * pcv->capacity * 2);
  memcpy(new_space, pcv->elems, pcv->elemsz * pcv->nelems);  // copy previous data
  free(pcv->elems);
  pcv->elems = new_space;
  pcv->capacity *= 2;
}

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

void cvec_append(cvector* pcv, void* elem) {
  if (pcv->capacity == pcv->nelems) {  // capacity full
    _cvec_increase_capacity(pcv);
  }
  memcpy((char*) pcv->elems + pcv->nelems * pcv->elemsz, elem, pcv->elemsz);  // append
  pcv->nelems++;
}

int cvec_insert(cvector* pcv, void* elem, int index) {
  if (index < 0 || index > pcv->nelems) {
    return false;
  }
  if (pcv->capacity == pcv->nelems) {  // capacity full
    _cvec_increase_capacity(pcv);
  }
  for (int i = pcv->nelems - 1; i >= index; i--) {  // shift to make room
    void* src = (char*) pcv->elems + i * pcv->elemsz;
    void* dst = (char*) pcv->elems + (i + 1) * pcv->elemsz;
    memcpy(dst, src, pcv->elemsz);
  }
  memcpy((char*) pcv->elems + index * pcv->elemsz, elem, pcv->elemsz);  // insert at index
  pcv->nelems++;
  return true;
}

void* cvec_get(cvector* pcv, int index) {
  if (index < 0 || index > pcv->nelems) {
    return NULL;
  }
  return (char*) pcv->elems + index * pcv->elemsz;
}

int cvec_index_of(cvector* pcv, void* elem) {
  for (int i = 0; i < pcv->nelems; i++) {  // loop through the elements
    void* current_elem = (char*) pcv->elems + i * pcv->elemsz;
    int is_match = true;
    for (int x = 0; x < pcv->elemsz; x++) {  // byte-by-byte comparison
      if (*((char*) elem + x) != *((char*) current_elem + x)) {
        is_match = false;
        break;
      }
    }
    if (is_match) {
      return i;
    }
  }
  return -1;
}

int cvec_remove(cvector* pcv, int index) {
  if (index < 0 || index > pcv->nelems) {
    return false;
  }
  for (int i = index + 1; i < pcv->nelems; i++) {
    void* src = (char*) pcv->elems + i * pcv->elemsz;
    void* dst = (char*) pcv->elems + (i - 1) * pcv->elemsz;
    memcpy(dst, src, pcv->elemsz);
  }
  pcv->nelems--;
  return true;
}

int cvec_set(cvector* pcv, int index, void* elem) {
  if (index < 0 || index > pcv->nelems) {
    return false;
  }
  void* dst = (char*) pcv->elems + index * pcv->elemsz;
  memcpy(dst, elem, pcv->elemsz);
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
