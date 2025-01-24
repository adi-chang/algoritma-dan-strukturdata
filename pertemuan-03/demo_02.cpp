/*
	demo program simulasi implementasi struktur data list 
	(dengan menggunakan array -> ArrayLsit)
	operasi:
	1. initialize : void
	2. add : void
	3. insert : void
	4. get : int
	5. print : void
	6. search : bool
	7. searchindex : int
	8. removeat : void
	9. remove : void
*/

#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 5

typedef struct List {
	
	int *data;
	int  size;
	int  capacity;
	
	// constructor untuk inisialize (create sebuah list kosong dengan jumlah storage awal sebesar INITIAL_SIZE)
	List() { 
		data = (int *)malloc(sizeof(int) * INITIAL_SIZE);
		size = 0;
		capacity = 0;
	}
	
	void add(int elemen) {
		if (size == capacity) {
			capacity += INITIAL_SIZE;
			data = (int *)realloc(data, capacity * sizeof(int));
		}
		data[size++] = elemen;
	}	

	void insert(int index, int elemen) {
		if (index >= 0 && index < size) {
			if (size == capacity) {
				capacity += INITIAL_SIZE;
				data = (int *)realloc(data, capacity * sizeof(int));
			}
			for ( int i = size ; i > index ; i-- )
				data[i] = data[i-1];
			data[index] = elemen;
			size++;
		}
		else {
			printf("sorry, index: %d tidak valid ...\n\n", index);
		}
	}	
	
	int get(int index) {
		if (index >= 0 && index < size) return data[index];
		return -1;
	}
	
	void print() {
		printf("list items [size: %d, capacity: %d] : ", size, capacity);
		if (size == 0)
			printf("empty list ...\n\n");
		else {
			for ( int i = 0 ; i < size ; i++ )
			printf("%d, ", get(i));
		printf("\n\n");
		}
	}
	
	void removeat(int index) {
		if (index >= 0 && index < size) {
			for ( int i = index ; i < size-1 ; i++ ) 
				data[i] = data[i+1];
			size--;	
		}
		else {
			printf("sorry, index: %d tidak valid ...\n\n", index);
		}
	}

	bool search(int elemen) {
		for ( int i = 0 ; i < size ; i++ )
			if (data[i] == elemen) return true;
		return false;
	}

	int search_index(int elemen) {
		for ( int i = 0 ; i < size ; i++ )
			if (data[i] == elemen) return i;
		return -1;
	}

	void remove(int elemen) {
		int idx = search_index(elemen);
		if (idx >= 0)
			removeat(idx);
		else 
			printf("sorry, elemen: %d tidak ditemukan.\n\n", elemen);
	}
	
} ArrayList;


int main() {
	// create sebuah variable yg bertipe ArrayList, 
	// constructor jalan otomatis untuk melakukan proses inisialisasi
	ArrayList mylist;
	
	// print kondisi awal (saat selesai inisialisasi)
	printf("kondisi awal:\n");
	mylist.print();

	// add elemen data 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ke dalam list
	for ( int i = 1 ; i <= 12 ; i++ ) {
		printf("add elemen: %2d ke dalam list\n", i);
		mylist.add(i);
		mylist.print();
	}
	
	// insert item 1, 2, 3, 4, 5 secara berurutan ke posisi index 0
	
	int idx = 0;
	
	for ( int i = 1 ; i <= 5 ; i++ ) {
		printf("insert elemen: %2d ke index: %d dalam list\n", i, idx);
		mylist.insert(idx, i);
		mylist.print();
	}	

	// get elemen at index: 3
	idx = 3;
	printf("elemen data pada index: %d = %d\n\n", idx, mylist.get(idx));
	
	// remove berturut-turut elemen pada index 0, 5, 10
	idx = 0;
	printf("remove elemen pada index: %d\n", idx);
	mylist.removeat(idx);
	mylist.print();

	idx = 5;
	printf("remove elemen pada index: %d\n", idx);
	mylist.removeat(idx);
	mylist.print();
				
	idx = 10;
	printf("remove elemen pada index: %d\n", idx);
	mylist.removeat(idx);
	mylist.print();
	
	// bagaimana jika yang dihapus index yang tidak ada ? 
	idx = 100;
	printf("remove elemen pada index: %d\n", idx);
	mylist.removeat(idx);
	mylist.print();

	// cari apakah elemen data 10 ada di dalam list atau tidak ? 

	int x = 10;

	if (mylist.search(x))
	{
		printf("elemen data: %d ditemukan di dalam list\n\n", x);
		printf("elemen data: %d ditemukan pada index: %d\n\n", x, mylist.search_index(x));
	}
	else 
		printf("elemen data: %d tidak ditemukan di dalam list\n\n", x);
	
	// menghapus elemen data: 1 (sebanyak 5x)
	x = 1;
	for ( int i = 1 ; i <= 5 ; i++ ) {
		printf("menghapus elemen data: %d\n", x);
		mylist.remove(x);
		mylist.print();	
	}
	

	return 0;
}
