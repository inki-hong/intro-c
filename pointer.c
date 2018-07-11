#include <stdio.h>

int main() {
	int i = 42;
	int j = 107000;
	int* p = &i;
	int* q = &j;

	// printf("%p\n", p);
	// printf("%d\n", *p);
	// printf("%p\n", q);
	// printf("%d\n", *q);

	// p = *q;
	// printf("%p\n", p);
	// printf("%d\n", *p);

	// int x;
	// int* r;
	// printf("%d\n", x);
	// printf("%p\n", r);
	// printf("%d\n", *r);

	int a = 5;
	double d = 2.5;
	int* ip = &a;
	double* dp = &d;

	printf("ip %p\n", ip);
	printf("value at ip %d\n", *ip);
	printf("dp %p\n", dp);
	printf("value at dp %f\n", *dp);

	dp = ip;  // bad
	printf("dp %p\n", dp);
	printf("value at dp %f\n", *dp);

	printf("end\n");
}
