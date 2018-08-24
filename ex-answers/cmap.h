typedef struct _cmap {
  size_t valsz;
  int nbuckets;
  void** buckets;
} cmap;

cmap* cmap_create(size_t valsz, int capacity_hint);
void cmap_destroy(cmap* pcm);
int cmap_contains_key(cmap* pcm, const char* key);
void* cmap_get(cmap* pcm, const char* key);
void cmap_put(cmap* pcm, const char* key, void* value);
int cmap_remove(cmap* pcm, const char* key);
void cmap_replace(cmap* pcm, const char* key, void* value);
