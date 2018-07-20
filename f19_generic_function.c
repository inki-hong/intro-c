#include <stdio.h>
#include <string.h>

int count_generic(void* key, void* arr, int n, char* type);

int main() {
    int int_array[] = {1, 2, 1, 3, 1, 4, 1, 5, 1};
    int int_count;

    float float_array[] = {0.1, 0.2, 0.3, 0.2};
    int float_count;

    char* str_array[] = {"apple", "orange", "apple"};
    int str_count;

    /**************************************/

    int x = 5;
    int_count = count_generic(&x, int_array, (int) (sizeof(int_array) / sizeof(int)), "int");
    printf("Count: %d \n", int_count);
}

int count_generic(void* key, void* arr, int n, char* type) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(type, "int") == 0) {
            int* ip = (int*) key;
            int* ia = (int*) arr;
            if (*ip == ia[i]) {
                count++;
            }
        }
    }
    return count;
}
