#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmap.h"

int _hash(const char* str) {
  int hash = 0;
  for (int i = 0; *(str+i) != '\0'; i++) {
    hash = 31 * hash + *(str+i);
  }
  return hash;
}

cmap* cmap_create(size_t valsz, int capacity_hint) {
  cmap* pcm = malloc(sizeof(cmap));
  pcm->valsz = valsz;
  pcm->nbuckets = capacity_hint;
  pcm->buckets = malloc(capacity_hint * sizeof(void*));
  for (int i = 0; i < pcm->nbuckets; i++) {
    char** current_bucket = (char**) pcm->buckets + i;
    *current_bucket = 0;
  }
  return pcm;
}

void cmap_put(cmap* pcm, const char* key, void* value) {
  if (cmap_contains_key(pcm, key)) {
    cmap_replace(pcm, key, value);
    return;
  }

  int bucket_index = abs(_hash(key) % pcm->nbuckets);
  // printf("Bucket index: %d\n", bucket_index);

  void** bucket = (void**) ((char**) pcm->buckets + bucket_index);

  // search the last element

  void* last_element = (void*) bucket;
  void* next_element;
  memcpy(&next_element, last_element, sizeof(void*));
  while (next_element != NULL) {
    last_element = next_element;
    memcpy(&next_element, last_element, sizeof(void*));
  }

  // create the new element

  size_t alloc_amt = sizeof(void*) + strlen(key) + 1 + pcm->valsz;
  // printf("Alloc amount: %zd\n", alloc_amt);
  void* element = malloc(alloc_amt);
  memset(element, 0, sizeof(void*));
  memcpy((char*) element + sizeof(void*), key, strlen(key) + 1);
  memcpy((char*) element + sizeof(void*) + strlen(key) + 1, value, pcm->valsz);
  printf("New element with key %s at %p\n", key, element);

  // link
  memcpy(last_element, &element, sizeof(void*));

  // alternative implementation

  // // create the new element
  // size_t alloc_amt = sizeof(void*) + strlen(key) + 1 + pcm->valsz;
  // // printf("Alloc amount: %zd\n", alloc_amt);
  // void* element = malloc(alloc_amt);
  // memset(element, 0, sizeof(void*));
  // memcpy((char*) element + sizeof(void*), key, strlen(key) + 1);
  // memcpy((char*) element + sizeof(void*) + strlen(key) + 1, value, pcm->valsz);
  // printf("New element with key %s at %p\n", key, element);
  //
  // if (*bucket == NULL) {
  //   printf("Bucket %d empty\n", bucket_index);
  //   // link
  //   *bucket = element;
  // } else {
  //   printf("Bucket %d has element\n", bucket_index);
  //
  //   // search the last element
  //   void* last_element = *bucket;
  //   // void* next_element = *((char**) last_element);  // same as below 2 lines
  //   void* next_element;
  //   memcpy(&next_element, last_element, sizeof(void*));
  //   while (next_element != NULL) {
  //     last_element = next_element;
  //     // next_element = *((char**) last_element);  // same as below line
  //     memcpy(&next_element, last_element, sizeof(void*));
  //   }
  //
  //   // link
  //   // *((char**) last_element) = element;  // same as below line
  //   memcpy(last_element, &element, sizeof(void*));
  // }
}

void* cmap_get(cmap* pcm, const char* key) {
  int bucket_index = abs(_hash(key) % pcm->nbuckets);
  void** bucket = (void**) ((char**) pcm->buckets + bucket_index);
  if (*bucket == NULL) {
    return NULL;
  }

  void* element = *bucket;
  while (element != NULL) {
    char* element_key = (char*) element + sizeof(void*);
    if (strcmp(key, element_key) == 0) {
      return (void*) ((char*) element + sizeof(void*) + strlen(key) + 1);
    }

    void* tmp;
    memcpy(&tmp, element, sizeof(void*));
    element = tmp;
  }
  return NULL;  // key not found
}

int cmap_contains_key(cmap* pcm, const char* key) {
  int bucket_index = abs(_hash(key) % pcm->nbuckets);
  void** bucket = (void**) ((char**) pcm->buckets + bucket_index);
  if (*bucket == NULL) {
    return false;
  }

  void* element = *bucket;
  while (element != NULL) {
    char* element_key = (char*) element + sizeof(void*);
    if (strcmp(key, element_key) == 0) {
      return true;
    }

    void* tmp;
    memcpy(&tmp, element, sizeof(void*));
    element = tmp;
  }
  return false;  // key not found
}

void cmap_replace(cmap* pcm, const char* key, void* value) {
  if ( ! cmap_contains_key(pcm, key)) {
    cmap_put(pcm, key, value);
    return;
  }

  int bucket_index = abs(_hash(key) % pcm->nbuckets);
  void** bucket = (void**) ((char**) pcm->buckets + bucket_index);

  assert(*bucket);

  void* element = *bucket;
  while (element != NULL) {
    char* element_key = (char*) element + sizeof(void*);
    if (strcmp(key, element_key) == 0) {
      void* element_value = (void*) ((char*) element + sizeof(void*) + strlen(key) + 1);
      memcpy(element_value, value, sizeof(pcm->valsz));
      return;
    }

    void* tmp;
    memcpy(&tmp, element, sizeof(void*));
    element = tmp;
  }
}

int cmap_remove(cmap* pcm, const char* key) {
  if ( ! cmap_contains_key(pcm, key)) {
    return false;
  }

  int bucket_index = abs(_hash(key) % pcm->nbuckets);
  void** bucket = (void**) ((char**) pcm->buckets + bucket_index);

  assert(*bucket);

  void* prev_element = (void*) bucket;
  void* element = *bucket;
  while (element != NULL) {
    void* next_element;
    memcpy(&next_element, element, sizeof(void*));

    char* element_key = (char*) element + sizeof(void*);
    if (strcmp(key, element_key) == 0) {
      memcpy(prev_element, &next_element, sizeof(void*));
      free(element);
      return true;
    }

    prev_element = element;
    element = next_element;
  }
  assert(false);
  return false;
}

void cmap_destroy(cmap* pcm) {
  void** bucket;
  for (int i = 0; i < pcm->nbuckets; i++) {  // for all buckets
    bucket = (void**) ((char**) pcm->buckets + i);
    if (*bucket == NULL) {
      continue;  // bucket empty
    }

    void* element = *bucket;
    while (element != NULL) {
      void* next_element;
      memcpy(&next_element, element, sizeof(void*));
      free(element);
      element = next_element;
    }
    *bucket = NULL;  // close out the bucket
  }
  free(pcm->buckets);  // optional
}

void _print_buckets(cmap* pcm) {
  void** bucket;
  for (int i = 0; i < pcm->nbuckets; i++) {
    bucket = (void**) ((char**) pcm->buckets + i);
    printf("Bucket %d at %p value %p\n", i, bucket, *bucket);
  }
}

int main() {
  // test hash function
  char* apple = "apple";
  char* banana = "banana";
  char* orange = "orange";
  char* strawberry = "strawberry";
  char* x = "x";
  printf("Hash of apple mod 4: %d\n", abs(_hash(apple) % 4));
  printf("Hash of banana mod 4: %d\n", abs(_hash(banana) % 4));
  printf("Hash of orange mod 4: %d\n", abs(_hash(orange) % 4));
  printf("Hash of strawberry mod 4: %d\n", abs(_hash(strawberry) % 4));
  printf("Hash of x mod 4: %d\n", abs(_hash(x) % 4));
  printf("----------------------------------------\n");

  // test cmap_create
  cmap* pcm = cmap_create(sizeof(double), 4);
  _print_buckets(pcm);
  printf("----------------------------------------\n");

  // test buckets after cmap_put
  double a = 1.5, b = 0.8, o = 2.4;
  cmap_put(pcm, "apple", &a);
  cmap_put(pcm, "banana", &b);
  cmap_put(pcm, "orange", &o);
  _print_buckets(pcm);
  printf("----------------------------------------\n");

  // test result of cmap_put
  char** bucket2 = (char**) pcm->buckets + 2;
  char** bucket3 = (char**) pcm->buckets + 3;
  void* pa = *((char**) *bucket2);
  void* pb = *((char**) *bucket3);
  double aa, bb;
  memcpy(&aa, *bucket2 + sizeof(void*) + strlen("apple") + 1, sizeof(double));
  memcpy(&bb, *bucket3 + sizeof(void*) + strlen("banana") + 1, sizeof(double));
  printf("%p %s %.1f\n", pa, *bucket2 + sizeof(void*), aa);
  printf("%p %s %.1f\n", pb, *bucket3 + sizeof(void*), bb);
  printf("----------------------------------------\n");

  // test cmap_get
  assert(cmap_get(pcm, "x") == NULL);
  assert(cmap_get(pcm, "strawberry") == NULL);
  double ap, bp, op;
  printf("Apple price at %p\n", cmap_get(pcm, "apple"));
  memcpy(&ap, cmap_get(pcm, "apple"), pcm->valsz);
  memcpy(&bp, cmap_get(pcm, "banana"), pcm->valsz);
  memcpy(&op, cmap_get(pcm, "orange"), pcm->valsz);
  printf("Prices: %.1f, %.1f, %.1f\n", ap, bp, op);
  printf("----------------------------------------\n");

  // test cmap_contains_key
  assert(cmap_contains_key(pcm, "x") == false);
  assert(cmap_contains_key(pcm, "strawberry") == false);
  assert(cmap_contains_key(pcm, "apple"));
  assert(cmap_contains_key(pcm, "banana"));
  assert(cmap_contains_key(pcm, "orange"));

  // test cmap_replace
  a = 1.6, b = 0.9, o = 2.5;
  cmap_replace(pcm, "apple", &a);
  cmap_replace(pcm, "banana", &b);
  cmap_replace(pcm, "orange", &o);
  memcpy(&ap, cmap_get(pcm, "apple"), pcm->valsz);
  memcpy(&bp, cmap_get(pcm, "banana"), pcm->valsz);
  memcpy(&op, cmap_get(pcm, "orange"), pcm->valsz);
  printf("Prices: %.1f, %.1f, %.1f\n", ap, bp, op);
  printf("----------------------------------------\n");

  // test cmap_remove
  assert(cmap_remove(pcm, "x") == false);
  assert(cmap_remove(pcm, "strawberry") == false);
  assert(cmap_remove(pcm, "apple"));
  assert(cmap_contains_key(pcm, "apple") == false);
  assert(cmap_contains_key(pcm, "banana"));
  assert(cmap_contains_key(pcm, "orange"));
  _print_buckets(pcm);

  // test result of cmap_remove
  void* po = *((char**) *bucket2);
  pb = *((char**) *bucket3);
  double oo;
  memcpy(&oo, *bucket2 + sizeof(void*) + strlen("orange") + 1, sizeof(double));
  memcpy(&bb, *bucket3 + sizeof(void*) + strlen("banana") + 1, sizeof(double));
  printf("%p %s %.1f\n", po, *bucket2 + sizeof(void*), oo);
  printf("%p %s %.1f\n", pb, *bucket3 + sizeof(void*), bb);
  printf("----------------------------------------\n");

  // test more cmap_remove
  assert(cmap_remove(pcm, "banana"));
  assert(cmap_remove(pcm, "orange"));
  assert(cmap_contains_key(pcm, "banana") == false);
  assert(cmap_contains_key(pcm, "orange") == false);
  _print_buckets(pcm);
  printf("----------------------------------------\n");

  // test cmap_destroy
  cmap_put(pcm, "apple", &a);
  cmap_put(pcm, "banana", &b);
  cmap_put(pcm, "orange", &o);
  cmap_destroy(pcm);
  _print_buckets(pcm);

  free(pcm);
  return 0;
}
