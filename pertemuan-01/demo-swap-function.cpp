#include <stdio.h>

void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
	printf("in function: a = %d, b = %d\n", *x, *y);
}

int main() {
	int a, b;
	a = 2; b = 5;
	printf("awal: a = %d, b = %d\n", a, b);
	printf("swap data value ...\n");
	swap(&a, &b);
	printf("akhir: a = %d, b = %d\n", a, b);
	return 0;
}
