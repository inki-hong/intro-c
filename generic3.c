#include <stdio.h>
#include <string.h>

int count_generic(void* key, void* arr, int n, int (*cmp)(void*, void*, int));
int cmp_int(int* a, int* b, int b_offset);
int cmp_float(float* a, float* b, int b_offset);
int cmp_str(char** a, char** b, int b_offset);

int main() {
	int int_array[] = {1, 2, 1, 3, 1, 4, 1, 5, 1};
	int int_count;

	int key = 1;
	int size = (int) (sizeof(int_array) / sizeof(int));
	int_count = count_generic(&key, int_array, size, cmp_int);
	printf("%d\n", int_count);
}

int count_generic(void* key, void* arr, int n, int (*cmp)(void*, void*, int)) {
	//
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (cmp(key, arr, i) == 0) {
			count++;
		}
	}
	//
	return count;
}

int cmp_int(int* a, int* b, int b_offset) {
	if (*a > *(b + b_offset)) {
		return 1;
	} else if (*a < *(b + b_offset)) {
		return -1;
	} else {
		return 0;
	}
}

int cmp_float(float* a, float* b, int b_offset) {
	if (*a > *(b + b_offset) + 0.000001) {
		return 1;
	} else if (*a < *(b + b_offset) - 0.000001) {
		return -1;
	} else {
		return 0;
	}
}

int cmp_str(char** a, char** b, int b_offset) {
	return strcmp(*a, *(b + b_offset));
	// if (strcmp(*a, *(b + b_offset)) > 1) {
	// 	return 1;
	// } else if (strcmp(*a, *(b + b_offset)) < 1) {
	// 	return -1;
	// } else {
	// 	return 0;
	// }
}
