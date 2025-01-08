#include <stdio.h>
#include <stdlib.h>

int main() {

	int x;
	
	x = 2;
	
	printf("nilai data variable x = %d\n", x);	
	printf("alamat memori dari variable x = %p\n", &x);
	
	int *p = NULL;
	
	p = &x;
	
	printf("nilai variable x, dilihat dari pointer p = %d\n", *p);
	
	p = (int *)malloc(sizeof(int));
	
	*p = 10;
	
	int *q = p;
	
	printf("nilai pointer p, dilihat dari q = %d\n", *q);
	printf("nilai pointer p, = %d\n", *p);
	
	
	
	return 0;
}

