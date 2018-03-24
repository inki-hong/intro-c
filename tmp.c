#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%zd\n", sizeof(int));
    printf("%zd\n", sizeof(long));
    printf("%zd\n", sizeof(float));
    printf("%zd\n", sizeof(double));

    int my_num = 5;
    int* ip = &my_num;
    printf("%p\n", ip);
    printf("%d\n", *ip);

//    long* lp = &my_num;
//    printf("%ld\n", *lp);

//    float* fp = &my_num;
//    printf("%.2f\n", *fp);

    int* ip2 = malloc(sizeof(int));
    printf("%p\n", ip2);
    printf("%d\n", *ip2);
}
