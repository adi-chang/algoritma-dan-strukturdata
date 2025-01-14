#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* random_n_value(int n) {
	int *arr = (int *)malloc(n * sizeof(n));
	for ( int i = 0 ; i < n ; i++ ) {
		arr[i] = rand() % 100 + 1;
	}
	return arr;
}

void print_array(int *items, int n) {
	printf("data items: ");
	// cara-2 kunjungan ke elemen data dalam pointer array (via index)
	for ( int i = 0 ; i < n ; i++ ) 
		printf("%d, ", items[i]);
	printf("\n");
}

void sorted(int *items, int n) {
	for ( int i = 0 ; i < n - 1 ; i++ ) {
		for ( int j = i + 1 ; j < n ; j++ ) {
			if (items[i] > items[j]) {
				int temp = items[i];
				items[i] = items[j];
				items[j] = temp;
 			}
		}
	}
}

bool binary_search(int items[], int n, int x) {
	int ki = 0, ka = n - 1;
	int c = 1;
	while (ki <= ka) {
		int t = ki + (ka - ki) / 2;
		// buka blokir di bawah ini, jika ingin mendebug proses eksekusi dari algoritma ini
		//printf("%3d. %3d == %3d ? %s\n", c++, items[t], x, items[t] == x ? "ya" : "tidak");
		if (items[t] == x) 
			return true;
		else if (items[t] < x) 
			ki = t + 1;
		else 
			ka = t - 1;
	}
	return false;
}

int main() {
	
	// random seed 
	srand(time(0));
	
	// set banyak data = 10
	int n = 10;
	
	// random n buah data int, dengan memanggil fungsi random_n_value 
	// fungsi ini akan mengembalikan sebuah pointer int yg pointing ke data array int
	int *data = random_n_value(n);
	
	// cara-1 kunjungan ke elemen data dalam pointer array (via helper pointer)
	int *p = data;
	for (int i = 0 ; i < n; i++) {
		printf("%d, ", *p);
		p++;
	}
	printf("\n\n");
	
	// memanggil fungsi print_array untuk menampilkan isi dalam variable array data
	print_array(data, n);
	
	printf("sorting data dengan metode bubble sort ... \n");
	sorted(data, n);

	// print elemen data setelah proses sorting
	print_array(data, n);
	
	// melakukan pencarian data 
	// data yang mau dicari, akan diinput oleh user, 
	// disimpan ke dalam variable x (int)
	int x;
	printf("\n\ncari data x ? "); scanf("%d", &x);
	
	// pencarian data dilakukan dengan memanggil fungsi binary_search (metode binary search)
	// fungsi ini membutuhkan 3 buah parameter input, yaitu:
	// 1. koleksi data berupa data array int
	// 2. banyak data 
	// 3. elemen data yang akan dicari
	// fungsi ini akan mengembalikan nilai boolean
	// kita tangkap lagi hasil pencariannya dengan conditional-if 
	// untuk menampilkan keterangan data tersebut ditemukan atau tidak ditemukan
	if (binary_search(data, n, x)) 
		printf("%d ditemukan dalam koleksi data.\n", x);
	else
		printf("%d tidak ditemukan dalam koleksi data.\n", x);
		
		
	return 0;
}
