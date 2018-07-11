#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_int(int key, int arr[], int n);
int count_float(float key, float arr[], int n);
int count_str(char* key, char* arr[], int n);
int count_generic(void* key, void* arr, int n);

int main() {
	int int_array[] = {1, 2, 1, 3, 1, 4, 1, 5, 1};
	int int_count;

	int_count = count_int(1, int_array, (int) (sizeof(int_array) / sizeof(int)));
	printf("%d\n", int_count);

	/**************************************/

	float float_array[] = {0.1, 0.2, 0.3, 0.2};
	int float_count;

	float_count = count_float(0.2, float_array, (int) (sizeof(float_array) / sizeof(float)));
	printf("%d\n", float_count);

	/**************************************/

	char* str_array[] = {"apple", "orange", "apple"};
	int str_count;

	str_count = count_str("apple", str_array, (int) (sizeof(str_array) / sizeof(char*)));
	printf("%d\n", str_count);

	/**************************************/

	char* key = malloc(6 * sizeof(char));
	key = strcpy(key, "apple");
	str_count = count_str(key, str_array, (int) (sizeof(str_array) / sizeof(char*)));
	printf("%d\n", str_count);

	/**************************************/

	int x = 5;
	count_generic(&x, int_array, (int) (sizeof(int_array) / sizeof(int)));
}

int count_int(int key, int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (key == arr[i]) {
			count++;
		}
	}
	return count;
}

int count_float(float key, float arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (key == arr[i]) {  // or key - arr[i] < very small number
			count++;
		}
	}
	return count;
}

int count_str(char* key, char* arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (key == arr[i]) {  // works if all are string literals
			count++;
		} else if (strcmp(key, arr[i]) == 0) {
			count++;
		}
	}
	return count;
}

int count_generic(void* key, void* arr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (*key == arr[i]) {
			count++;
		}
	}
	return count;
}
