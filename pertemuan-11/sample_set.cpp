#include <stdio.h>
#include "SET.cpp"

int main() {
	
	Set myset;
	
	int data_source[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 5 };
	int another_source[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	
	int n = sizeof(data_source) / sizeof(int);
	
	for ( int i = 0 ; i < n ; i++ ) {
		printf("add item: %d ke dalam variable bertipe set.\n", data_source[i]);
		myset.add(data_source[i]);
	}
	
	myset.update(another_source, sizeof(another_source)/sizeof(int));
	
	myset.display();
	
	printf("\nhapus elemen dari dalam set.\n");
	
	int x = 1;
	printf("remove elemen: %d dari dalam set.\n", x);
	myset.remove(x);
	x = 8;
	printf("remove elemen: %d dari dalam set.\n", x);
	myset.remove(x);
	x = 15;
	printf("remove elemen: %d dari dalam set.\n", x);
	myset.remove(x);
	x = 20;
	printf("remove elemen: %d dari dalam set.\n", x);
	myset.remove(x);
	
	myset.display();
	
	return 0;
}
