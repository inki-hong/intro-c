#include <stdio.h>
#include <pthread.h>

void* func(void* arg);

int main() {
    pthread_t thread_1, thread_2;

    pthread_create(&thread_1, NULL, func, "hello");
    pthread_create(&thread_2, NULL, func, "hi");

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    return 0;
}

void* func(void* arg) {
    printf("%s \n", (char*) arg);
}
