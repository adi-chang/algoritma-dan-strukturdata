#include <stdio.h> 
#include <stdlib.h>
#include "SET.cpp"
#define N 500000

int* read_file_content(const char *filename) {
	int *arr = NULL; 
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("Error: gagal membuka file ...\n");
	}
	else {
		arr = (int *)malloc(sizeof(int) * N);
		fread(arr, sizeof(int), N, fp);
		fclose(fp);	
	}
	return arr;
}

int main() {
	
	int *arr = read_file_content("data.txt");
	
//	for ( int i = 0 ; i < N ; i++ ) {
//		printf("%d ", arr[i]);
//	}
	
	Set myset;
	myset.update(arr, N);
	
	printf("Banyak item unik: %d\n", myset.size);
	myset.display();
	printf("Nilai minimum: %d\n", myset.get_minimum());
	printf("Nilai maximum: %d\n", myset.get_maximum());
	
	return 0;
}
