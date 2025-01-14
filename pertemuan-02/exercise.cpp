#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct numberGenerator {
	
	int size;
	int *arr;
	
	numberGenerator(int n) {
		size = n;
		arr = (int *)malloc(sizeof(int) * size);
		memset(arr, 0, sizeof(int)*size);
	}
	
	void print_items() {
		printf("size: %d,\nitem data:\n", size);
		for ( int i = 0 ; i < size ; i++ ) 
			printf("%d, ", arr[i]);
		printf("\n");
	}
	
	void random_values() {
		int i = 0; 
		while (i < size) {
			int x;
			do {
				x = rand() % 100 + 1;
				bool temu = false;
				for ( int j = 0 ; j <= i ; j++ ) {
					if (arr[j] == x) {
						temu = true;
						break;
					}
				}			
				if (!temu) 
					break;
			} while (true);
			arr[i] = x;
			i++;
		}
	}
	
	void sort() {
		for ( int i = 0 ; i < size - 1 ; i++ ) {
			for ( int j = i + 1 ; j < size ; j++ ) {
				if ( arr[i] > arr[j] ) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	
	bool search(int x) {
		for ( int i = 0 ; i < size ; i++ )
			if (arr[i] == x) return true;
		return false;
	}
	
};

typedef struct numberGenerator NumberGenerator;

int main() {
	// create variabel struct, dan set nilai n = 15 (menampung 15 buah elemen data)
	NumberGenerator gen(15);
	
	// print initial values
	gen.print_items();

	// random n buah data acak unik
	gen.random_values();
	
	// print kembali koleksi data yang ada, setelah kita populate dengan data
	gen.print_items();
			
	// sort koleksi data
	gen.sort();
	
	// print data kembali after sorting 
	gen.print_items();
	
	// cari elemen data 1 apakah ada di dalam koleksi data
	if (gen.search(1)) 
		printf("%d ditemukan\n", 1);
	else 
		printf("%d tidak ditemukan\n", 1);
	
	
	
	return 0;	
}
