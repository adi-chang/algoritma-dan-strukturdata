#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	const char *data;
	struct node *prev;
	struct node *next;
} Node;


typedef struct linkedlist {
	
	Node *head;
	Node *tail;
	int count;
	
	linkedlist() {
		printf("constructor in run ...\n\n");
		head = tail = NULL;
		count = 0;	
	}
	
	void add(const char *value) {
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->data = value;
		newNode->prev = NULL;
		newNode->next = NULL;
		if (head == NULL) 
			head = tail = newNode;
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		count++;
	}
	
	void insert(const char *value, int index) {
		if (index_is_valid(index)) {
			Node *newNode = (Node*)malloc(sizeof(Node));
			newNode->data = value;
			newNode->prev = NULL;
			newNode->next = NULL;
			if (index == 0) {
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			else {
				Node *p = head;
				int idx = 0;
				while (idx < index-1) {
					p = p->next;
					idx++;
				}
				newNode->next = p->next;
				p->next->prev = newNode;
				p->next = newNode;
				newNode->prev = p;
			}
			count++;
		}
		else 
			printf("sorry, index is not valid ...\n");
	}
	
	void print_forward() {
		printf("list items: forward [count = %d] : ", count);
		if (head == NULL) 
			printf("empty list ...\n\n");
		else {
			Node *p = head;
			while ( p != NULL ) {
				printf("%s -> ", p->data);
				p = p->next;
			}
			printf("NULL \n\n");
		}
	}
	
	void print_backward() {
		printf("list items: backward [count = %d] : ", count);
		if (head == NULL) 
			printf("empty list ...\n\n");
		else {
			Node *p = tail;
			while ( p != NULL ) {
				printf("%s -> ", p->data);
				p = p->prev;
			}
			printf("NULL \n\n");
		}
	}
	
	void display() {
		print_forward();
	}
	
	const char* get_first_item() {
		if (head != NULL) {
			return head->data;
		}
		return "None";
	}
	
	const char* get_last_item() {
		if (tail != NULL) {
			return tail->data;
		}
		return "None";
	}
	
	bool index_is_valid(int index) {
		return index >= 0 && index < count;
	}
	
	const char* get_item_at(int index) {
		if (index_is_valid(index)) {
			Node *p = head;
			int idx = 0;
			while (idx < index) {
				p = p->next;
				idx++;
			}
			return p->data;	
		}
		else
			return "index is not valid ...";
	}
	
	bool contain(const char *value) {
		if (head != NULL) {
			Node *p = head;
			while ( p != NULL ) {
				if (stricmp(p->data, value) == 0) return true;
				p = p->next;
			}
		}
		return false;
	}

	int index_of(const char *value) {
		if (head != NULL) {
			int idx = 0;
			Node *p = head; 
			while ( p != NULL ) {
				if (stricmp(p->data, value) == 0) return idx;
				p = p->next;
				idx++;
			}
		}
		return -1;
	}
	
	void remove_at(int index) {
		if (index_is_valid(index)) {
			if (index == 0) {
				Node *p = head;
				head = p->next;
				p->next = NULL;
				head->prev = NULL;
				free(p);
			}
			else if (index == count - 1) {
				Node *p = tail;
				tail = p->prev;
				p->prev = NULL;
				tail->next = NULL;
				free(p);
			}
			else {
				Node *p = head;
				int idx = 0;
				while ( idx < index - 1 ) {
					p = p->next;
					idx++;
				}
				Node *q = p->next;
				p->next = q->next;
				q->next->prev = p;
				q->next = NULL;
				q->prev = NULL;
				free(q);
			}
			count--;
		}	
		else
			printf("sorry, index is not valid ...\n");	
	}	

	void remove(const char *value) {
		int idx = index_of(value);
		if (idx >= 0)
			remove_at(idx);
	}
	
	void replace_item_at(const char *value, int index) {
		if (index_is_valid(index)) {
			Node *p = head;
			int idx = 0;
			while (idx < index) {
				p = p->next;
				idx++;
			}
			p->data = value;
		}
		else 
			printf("sorry, index is not valid ...\n");
	}
	
	void clear() {
		tail = NULL;
		while ( head != NULL ) {
			Node *p = head;
			head = p->next;
			p->next = NULL;
			free(p);
		}
		head = NULL;
		count = 0;
	}
	
	void sort() {
		if (head != NULL && head != tail) {
			Node *p = head;
			while ( p->next != NULL ) {
				Node *q = p->next;
				while ( q != NULL ) {
					if ( stricmp(p->data, q->data) > 0 ) {
						const char *temp = p->data;
						p->data = q->data;
						q->data = temp;
					}
					q = q->next;
				}
				p = p->next;
			}
		}
	}
		
	~linkedlist() {
		printf("destructor is run ... \n\n");
		tail = NULL;
		while ( head != NULL ) {
			Node *p = head;
			head = p->next;
			p->next = NULL;
			free(p);
		}
		head = NULL;
		count = 0;
	}	
	
} DoublyLinkedList;


int main() {
	
	printf("create variable mylist: DoubleLinkedList.\n\n");
	DoublyLinkedList mylist;
	
	// print kondisi awal 
	mylist.print_forward();
	
	// prepare data source
	int n = 5;
	const char *source[] = { "Budi" , "William" , "Susan" , "Gunawan" , "Andi" };
	
	// operasi : add item to mylist
	for ( int i = 0 ; i < n ; i++ ) {
		printf("operasi: add item: %s ke dalam mylist.\n", source[i]);
		mylist.add(source[i]);
	}
	printf("\n");
	
	// print kondisi setelah operasi add item data
	mylist.print_forward();
	
	int idx = 2;
	printf("item data pada posisi index: %d adalah = %s\n\n", idx, mylist.get_item_at(idx));
	
	// operasi : search item data
	
	const char *searchItem = "andi";
	
	printf("item: %s ada di dalam mylist ? %s\n\n", 
		searchItem, mylist.contain(searchItem) ? "Ada" : "Tidak");
	
	const char *nama = "Jamila";
	idx = 0;
	
	printf("operasi: sisip item: %s at index: %d\n", nama, idx);
	mylist.insert(nama,  idx); 
	mylist.display();
	
	nama = "Robert";
	idx = mylist.count-1;
	printf("operasi: sisip item: %s at index: %d\n", nama, idx);
	mylist.insert(nama,  idx); 
	mylist.display();
	
	nama = "Juliana";
	idx = 3;
	printf("operasi: sisip item: %s at index: %d\n", nama, idx);
	mylist.insert(nama,  idx); 
	mylist.display();
	
	// operasi : remove at 
	// remove : index = 0
	// remove : index terakhir 
	// remove : index dari item: Juliana 
	
	idx = 0; 
	printf("operasi: remove at index: %d\n", idx);
	mylist.remove_at(idx);
	mylist.display();
	
	idx = mylist.count - 1;
	printf("operasi: remove at index: %d\n", idx);
	mylist.remove_at(idx);
	mylist.display();
	
	idx = mylist.index_of("Juliana");
	printf("operasi: remove at index: %d\n\n", idx);
	mylist.remove_at(idx);
	mylist.display();
	
	// operasi remove by value
	
	nama = "Susan";
	
	printf("operasi: remove elemen item: %s dari dalam mylist.\n\n", nama);
	mylist.remove(nama);
	mylist.display();
		
	// operasi replace item at
	
	nama = "Robert";
	idx = mylist.index_of(nama);

	const char *namaTarget = "Rudi";

	printf("operasi: replace item at index: %d [%s] menjadi: %s.\n\n", idx, nama, namaTarget);
	mylist.replace_item_at(namaTarget, idx);
	mylist.display();	
	
	// hapus semua elemen data dala mylist
	mylist.clear();

	// reset, add kembali item data nya 
	for ( int i = 0 ; i < n ; i++ ) {
		printf("operasi: add item: %s ke dalam mylist.\n", source[i]);
		mylist.add(source[i]);
	}
	printf("\n");

	mylist.display();

	// sort data 
	printf("sorting data ...\n\n");
	mylist.sort();

	// cek hasil setelah sort 
	mylist.display();

	
	return 0;
}
