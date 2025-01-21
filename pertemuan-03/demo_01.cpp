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

typedef struct {
	int *data;
	int  size;
	int  capacity;
} ArrayList;

// fungsi inisialize untuk mencreate sebuah list kosong 
void initialize(ArrayList *list) {
	list->data = (int *)malloc(sizeof(int) * INITIAL_SIZE);
	list->size = 0;
	list->capacity = INITIAL_SIZE;
}

// operasi add elemen data ke dalam list. (secara sisip belakang)
void add(ArrayList *list, int elemen) {
	if (list->size == list->capacity) {
		list->capacity += INITIAL_SIZE;
		list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
	}
	list->data[list->size] = elemen;
	list->size++;
}

// operasi insert: sisip mulai dari index 0 sampe posisi index size-1
void insert(ArrayList *list, int index, int elemen) {
	if (index >= 0 && index < list->size) { 
		if (list->size == list->capacity) {
			list->capacity += INITIAL_SIZE;
			list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
		}
		for ( int i = list->size ; i > index ; i-- ) 
			list->data[i] = list->data[i-1];
		list->data[index] = elemen;
		list->size++;
	}
	else {
		printf("sorry, index: %d tidak valid ...\n\n", index);
	}
}

// operasi untuk menampilkan semua elemen data dalam list
void print_list(ArrayList list) {
	printf("list items [size: %d, capacity: %d] : ", list.size, list.capacity);
	if (list.size == 0)
		printf("empty list ...\n\n");
	else {
		for ( int i = 0 ; i < list.size ; i++ )
			printf("%d, ", list.data[i]);
		printf("\n\n");
	}
}

// operasi get: mengambil elemen data pada index tertentu
// validasi indexnya, valid atau tidak
int get(ArrayList list, int index) {
	if (index >= 0 && index < list.size)
		return list.data[index];
	return -1;
}

// operasi removeat: menghapus elemen data pada index tertentu
// index harus berupa index yang valid
void removeat(ArrayList *list, int index) {
	if (index >= 0 && index < list->size) {
		for ( int i = index ; i < list->size-1 ; i++ ) 
			list->data[i] = list->data[i+1];
		list->size--;	
	}
	else {
		printf("sorry, index: %d tidak valid ...\n\n", index);
	}
}

// operasi search : mencari elemen data (return bool)
bool search(ArrayList *list, int elemen) {
	for ( int i = 0 ; i < list->size ; i++ )
		if (list->data[i] == elemen) return true;
	return false;
}

// operasi search_index : mencari index dari elemen data tertentu (return int)
int search_index(ArrayList *list, int elemen) {
	for ( int i = 0 ; i < list->size ; i++ )
		if (list->data[i] == elemen) return i;
	return -1;
}

// operasi remove : menghapus elemen tertentu (yg pertama sekali ditemui di dalam list)
void remove(ArrayList *list, int elemen) {
	int idx = search_index(list, elemen);
	if (idx >= 0) 
	  removeat(list, idx);
	else 
		printf("sorry, elemen: %d tidak ditemukan.\n\n", elemen);
}

int main() {
	// create sebuah variable yg bertipe ArrayList
	ArrayList mylist;
	
	// inisialisasi variable mylist
	initialize(&mylist);
	
	// print kondisi awal (saat selesai inisialisasi)
	printf("kondisi awal:\n");
	print_list(mylist);

	// add elemen data 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ke dalam list
	for ( int i = 1 ; i <= 12 ; i++ ) {
		printf("add elemen: %2d ke dalam list\n", i);
		add(&mylist, i);
		print_list(mylist);
	}
	
	// insert item 1, 2, 3, 4, 5 secara berurutan ke posisi index 0
	
	int idx = 0;
	
	for ( int i = 1 ; i <= 5 ; i++ ) {
		printf("insert elemen: %2d ke index: %d dalam list\n", i, idx);
		insert(&mylist, idx, i);
		print_list(mylist);
	}	

	// get elemen at index: 3
	idx = 3;
	printf("elemen data pada index: %d = %d\n\n", idx, get(mylist, idx));
	
	// remove berturut-turut elemen pada index 0, 5, 10
	idx = 0;
	printf("remove elemen pada index: %d\n", idx);
	removeat(&mylist, idx);
	print_list(mylist);

	idx = 5;
	printf("remove elemen pada index: %d\n", idx);
	removeat(&mylist, idx);
	print_list(mylist);
				
	idx = 10;
	printf("remove elemen pada index: %d\n", idx);
	removeat(&mylist, idx);
	print_list(mylist);
	
	// bagaimana jika yang dihapus index yang tidak ada ? 
	idx = 100;
	printf("remove elemen pada index: %d\n", idx);
	removeat(&mylist, idx);
	print_list(mylist);
	
	// cari apakah elemen data 10 ada di dalam list atau tidak ? 
	
	int x = 10;
	
	if (search(&mylist, x)) {
		printf("elemen data: %d ditemukan di dalam list\n\n", x);
		printf("elemen data: %d ditemukan pada index: %d\n\n", x, search_index(&mylist, x));
	}
	else {
		printf("elemen data: %d tidak ditemukan di dalam list\n\n", x);
	}
	
	// menghapus elemen data : 1 (sebanyak 5x)
	x = 1;
	for (int i = 1; i <= 5; i++) {
		printf("menghapus elemen data: %d\n", x);
		remove(&mylist, x);
		print_list(mylist);	
	}
	
	return 0;
}
