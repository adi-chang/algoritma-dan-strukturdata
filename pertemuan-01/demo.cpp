#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct RandomNumberGenerator {
	
	int n;
	int *items;
	
	RandomNumberGenerator(int count) {
		n = count;
		items = (int *)malloc(sizeof(int)*n);	
		random();	
	}
	
	void random() {
		items = (int *)malloc(sizeof(int)*n);		
		for ( int i = 0 ; i < n ; i++ ) {
			int x = rand() % 100 + 1;
			items[i] = x;
		}
	}
	
	int sum() {
		int jumlah = 0;
		for ( int i = 0 ; i < n ; i++ ) {
			jumlah += items[i]; 
		}
		return jumlah;
	}
	
	double average() {
		return 1.0 * sum() / n;
	}
	
	void print() {
		printf("N: %d\n", n);
		printf("data items:\n");
		for ( int i = 0 ; i < n ; i++ ) {
			printf("%5d", items[i]);
			if (i < n-1) printf(", ");
			if ((i+1) % 15 == 0) printf("\n");
		}
		printf("\n");
	}
	
	void show_genap() {
		printf("data genap:\n");
		bool print = false;
		int c = 0;
		for ( int i = 0 ; i < n ; i++ ) {
			if (items[i] % 2 == 0) {
				printf("%5d, ", items[i]);
				c++;
				print = false;
			}
			if (c != 0 && (c % 15) == 0 && !print) {
				printf("\n");
				print = true;	
			}
		}
		printf("\nBanyak Bilangan Genap = %d\n", c);
	}
	
	void show_ganjil() {
		printf("data ganjil:\n");
		bool print = false;
		int c = 0;
		for ( int i = 0 ; i < n ; i++ ) {
			if (items[i] % 2 != 0) {
				printf("%5d, ", items[i]);
				c++;
				print = false;
			}
			if (c != 0 && (c % 15) == 0 && !print) {
				printf("\n");	
				print = true;
			} 
		}
		printf("\nBanyak Bilangan Ganjil = %d\n", c);
	}
	
};

int main() {
	srand(time(NULL));
	struct RandomNumberGenerator rng(500);
	rng.print();
	printf("\n");
	printf("jumlah data = %d\n", rng.sum());
	printf("\n");
	printf("rata - rata data = %.2lf\n", rng.average());
	printf("\n");
	rng.show_genap();
	printf("\n");
	rng.show_ganjil();
	return 0;
}



