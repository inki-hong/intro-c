#include <stdio.h>
#include <string.h>

void find_max(void* arr, void* dest, int n, char* type);

int main() {
    int int_array[] = {1, 2, 1, 3, 1, 4, 1, 5, 1};
    int max_int = 0;

    float float_array[] = {0.1, 0.2, 0.3, 0.2};
    float max_float = 0.0;

    char* str_array[] = {"apple", "orange", "apple"};
    char* max_str = "";

    /**************************************/

    find_max(int_array, &max_int, (int) (sizeof(int_array) / sizeof(int)), "int");
    printf("Max int: %d \n", max_int);

    // ...
}

void find_max(void* arr, void* dest, int n, char* type) {
    if (strcmp(type, "int") == 0) {
        // ...
    } else if (strcmp(type, "float") == 0) {
        // ...
    } else {
        // ...
    }
}
