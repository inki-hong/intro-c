typedef struct _cvector {
  size_t elemsz;
  int nelems;
  void* elems;
  int capacity;
} cvector;

cvector* cvec_create(size_t elemsz, int capacity_hint);
void cvec_destroy(cvector* pcv);
void cvec_append(cvector* pcv, void* elem);
int cvec_insert(cvector* pcv, void* elem, int index);
void* cvec_get(cvector* pcv, int index);
int cvec_index_of(cvector* pcv, void* elem);
int cvec_remove(cvector* pcv, int index);
int cvec_set(cvector* pcv, int index, void* elem);
void cvec_sort(cvector* pcv, int (*cmp)(const void*, const void*));
