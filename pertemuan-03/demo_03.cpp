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
#include <string.h>
#include <ctype.h>
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
		if (index_is_valid(index)) {
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
	
	bool index_is_valid(int index) {
		return index >= 0 && index < size;
	}
	
	int get(int index) {
		if (index_is_valid(index)) return data[index];
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
		if (index_is_valid(index)) {
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


bool is_numeric(const char *str) {
    for ( int i = 0 ; i < strlen(str) ; i++ ) 
        if (!isdigit(str[i])) return false;
    return true;
}


int get_int(const char *prompt) {
    char input[5];
    do {
        printf("%s ", prompt); scanf("%s", input);   
        if (is_numeric(input))
        	return atoi(input);
    } while (true);
}



int main() {
	// create sebuah variable yg bertipe ArrayList, 
	// constructor jalan otomatis untuk melakukan proses inisialisasi
	ArrayList mylist;
	
	bool lanjut = true;
	int choice, idx, value;

  do {
    system("cls");

    printf("<<< M E N U >>>\n");
    printf("---------------------\n");
    printf("1. Show Data\n");
    printf("2. Get Value By Index\n");
    printf("3. Add\n");
    printf("4. Insert\n");
    printf("5. Search\n");
    printf("6. Remove By Index\n");
    printf("7. Remove By Value\n");
    printf("0. Quit\n");
    printf("---------------------\n");
    
    choice = get_int("Menu [0..7] ?"); 
    
    switch(choice) {
    	case 1:
    		system("cls");
    		printf("1. Show Data\n\n");
				mylist.print();
    		system("pause");
    		break;
    	case 2:
    		system("cls");
    		printf("2. Get Value By Index\n\n");
    		mylist.print();
    		idx = get_int("Index ?");
    		if(mylist.index_is_valid(idx)) 
					printf("elemen data pada index: %d adalah: %d\n\n", idx, mylist.get(idx));
				else {
					if (mylist.size == 0)
						printf("sorry, index: %d tidak valid\n\n", idx);
					else 
						printf("sorry, index: %d tidak valid [index valid: 0 - %d]\n\n", idx, mylist.size-1);
				}
    		system("pause");
    		break;
			case 3:
    		system("cls");
    		printf("3. Add\n\n");
    		value = get_int("New Item Value ?");
    		mylist.add(value);
    		printf("\nnew item: %d added\n\n", value);
    		system("pause");
				break;
			case 4:
				system("cls");
				printf("4. Insert\n\n");
				mylist.print();
				value = get_int("New Item Value ?");
				idx = get_int("Index ?");
				if (mylist.index_is_valid(idx)) {
					mylist.insert(idx, value);
					printf("\nnew item: %d inserted at index: %d\n\n", value, idx);
				}
				else {
					if (mylist.size == 0)
						printf("sorry, index: %d tidak valid\n\n", idx);
					else 
						printf("sorry, index: %d tidak valid [index valid: 0 - %d]\n\n", idx, mylist.size-1);
				} 
				system("pause");
    		break;
    	case 5:
    		system("cls");
    		printf("5. Search\n\n");
    		value = get_int("Item Value ?");
    		if(mylist.search(value))
    			printf("Item: %d ditemukan dalam list data.\n\n", value);
    		else 
    			printf("sorry, item: %d tidak ditemukan dalam list data.\n\n", value);
				system("pause");
    		break;
    	case 6:
    		system("cls");
    		printf("6. Remove By Index\n\n");
				mylist.print();
				idx = get_int("Index ?");
				if (mylist.index_is_valid(idx)) {
					mylist.removeat(idx);
					printf("Item at index: %d berhasil diremove.\n\n", idx);
				}
				else {
					if (mylist.size == 0)
						printf("sorry, index: %d tidak valid\n\n", idx);
					else 
						printf("sorry, index: %d tidak valid [index valid: 0 - %d]\n\n", idx, mylist.size-1);
				}
				system("pause");
    		break;
    	case 7:
    		system("cls");
    		printf("7. Remove By Value\n\n");
    		mylist.print();
    		value = get_int("Item Value ?");
    		if (mylist.search(value)) {
    			mylist.remove(value);
    			printf("Item: %d berhasil diremove.\n\n", value);
				}
				else {
					printf("sorry, item: %d tidak ditemukan dalam list data.\n\n", value);
				}
				system("pause");
    		break;
			case 0:
    		lanjut = false;
    		break;
    	default:
    		printf("sorry, nomor menu tidak tersedia ...\n\n");
    		system("pause");
		}
  	
  	if (!lanjut) break;
      
  } while (1);


	

	return 0;
}
