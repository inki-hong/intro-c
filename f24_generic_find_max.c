#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>

void find_max(void* arr, void* dest, int n, int elemsz, int (*cmp)(void*, void*));
int cmp_int(int* a, int* b);
int cmp_float(float* a, float* b);
int cmp_str(char** a, char** b);

int main() {
	int int_array[] = {1, 2, 1, 3, 1, 4, 1, 5, 1};
	int int_max = INT_MIN;
	int n = sizeof(int_array) / sizeof(int);
	find_max(int_array, &int_max, n, sizeof(int), cmp_int);
	printf("Max %d\n", int_max);
	
	float float_array[] = {0.1, 0.2, 0.3, 0.2};
	float float_max = FLT_MIN;
	n = sizeof(float_array) / sizeof(float);
	find_max(float_array, &float_max, n, sizeof(float), cmp_float);
	printf("Max %.2f\n", float_max);

	return 0;
}

void find_max(void* arr, void* dest, int n, int elemsz, int (*cmp)(void*, void*)) {
	int i;
	for (i = 0; i < n; i++) {
		char* char_arr = (char*) arr;
		if (cmp(char_arr + (elemsz * i), dest) > 0) {
			memcpy(dest, char_arr + (elemsz * i), elemsz);
		}
	}
}

int cmp_int(int* a, int* b) {
	if (*a > *b) {
		return 1;
	} else if (*a < *b) {
		return -1;
	} else {
		return 0;
	}
}

int cmp_float(float* a, float* b) {
	if (*a > *b + 0.000001) {
		return 1;
	} else if (*a < *b - 0.000001) {
		return -1;
	} else {
		return 0;
	}
}

int cmp_str(char** a, char** b) {
	return strcmp(*a, *b);
}
