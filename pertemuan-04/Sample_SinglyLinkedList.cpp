#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node *next;
} Node;

typedef struct {
	Node *head;
	Node *tail;
	int   count;
} SinglyLinkedList;

void initialize(SinglyLinkedList *list) {
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
}

void add(SinglyLinkedList *list, int item) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = item;
	newNode->next = NULL;
	if (list->head == NULL) 
		list->head = list->tail = newNode;
	else {
		list->tail->next = newNode;
		list->tail = newNode;
	}
	list->count++;
}

bool index_is_valid(SinglyLinkedList *list, int index) {
	return list->count > 0 && index >= 0 && index < list->count;
}

void insert(SinglyLinkedList *list, int item, int index) {
	if (index_is_valid(list, index)) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = item;
		newNode->next = NULL;
		if (index == 0) {
			newNode->next = list->head;
			list->head = newNode;
		}
		else {
			Node *p = list->head;
			int i = 0;
			while (i++ < index-1) {
				p = p->next;
			}
			newNode->next = p->next;
			p->next = newNode;
		}
		list->count++;
	}
	else 
		printf("Sorry, index is not valid ...\n\n");
}

void remove_at(SinglyLinkedList *list, int index) {
	if (index_is_valid(list, index)) {
		if (index == 0) {
			Node *p = list->head;
			list->head = p->next;
			p->next = NULL;
			free(p);
		}
		else if (index == list->count-1) {
			Node *p = list->head;
			int i = 0;
			while (i++ < index-1) {
				p = p->next;
			}
			Node *q = p->next;
			p->next = NULL;
			list->tail = p;
			free(q);
		}
		else {
			Node *p = list->head;
			int i = 0;
			while (i++ < index-1) {
				p = p->next;
			}
			Node *q = p->next;
			p->next = q->next;
			q->next = NULL;
			free(q);
		}
		list->count--;
	}
	else
		printf("Sorry, index is not valid ...\n\n");
}

bool search(SinglyLinkedList *list, int item) {
	Node *p = list->head;
	while (p != NULL) {
		if (p->data == item) return true;
		p = p->next;
	}
	return false;
}

int search_index(SinglyLinkedList *list, int item) {
	Node *p = list->head;
	int index = 0;
	while (p != NULL) {
		if (p->data == item) return index;
		p = p->next; 
		index++;
	}
	return -1;
}

void remove(SinglyLinkedList *list, int item) {
	int index = search_index(list, item);
	if (index_is_valid(list, index)) {
		remove_at(list, index);
	}
	else 
		printf("Sorry, item: %d tidak ditemukan ...\n\n", item);
}

void print_items(SinglyLinkedList *list) {
	printf("data items [count: %d] : ", list->count);
	if (list->count == 0)
		printf("empty list ...\n\n");
	else {
		Node *p = list->head;
		while ( p != NULL ) {
			printf("%d -> ", p->data);
			p = p->next;
		}
		printf("NULL\n\n");
	}
}

int main() {
	
	// create variable mylist: SinglyLinkedList
	SinglyLinkedList mylist;
	
	// lakukan inisialisasi ke variable mylist
	// prosedur ini akan melakukan proses inisialisasi ke pointer head, tail dan count
	// head dan tail di set NULL
	// count di set 0 (belum ada item data)
	printf("inisialisasi linkedlist.\n\n");
	initialize(&mylist);
	
	// cek isi list setelah inisialisasi
	printf("isi linkedlist setelah inisialisasi:\n");
	print_items(&mylist);
	
	// demo penambahan item data [1..5] ke ke dalam linkedlist mylist
	for ( int i = 1 ; i <= 5 ; i++ ) {
		printf("add item: %d ke dalam list.\n\n", i);
		add(&mylist, i);
		printf("isi linkedlist setelah add item: %d.\n", i);
		print_items(&mylist);
	}

	// cek isi mylist	
	printf("\nisi linkedlist setelah selesai melakukan operasi add:\n");
	print_items(&mylist);

	// demo insert item data

	printf("insert item: 10 ke index: 0 linkedlist.\n\n");
	insert(&mylist, 10, 0);

	printf("isi linkedlist setelah insert item: 10 ke index: 0.\n");
	print_items(&mylist);
	
	int idx = mylist.count-1;
		
	printf("insert item: 11 ke index: %d linkedlist.\n\n", idx);
	insert(&mylist, 11, mylist.count-1);

	printf("isi linkedlist setelah insert item: 11 ke index: %d.\n", idx);
	print_items(&mylist);
	
	printf("insert item: 12 ke index: 2 linkedlist.\n\n");
	insert(&mylist, 12, 2);
	
	printf("isi linkedlist setelah insert item: 12 ke index: 2.\n");
	print_items(&mylist);
	
	// demo cari data
	
	int x = 10; 
	
	printf("cari item data: %d ? \n", x);
	if (search(&mylist, x)) 
		printf("item: %d ditemukan dalam list.\n\n", x);
	
	x = 100;	
	printf("cari item data: %d ? \n", x);
	if (search(&mylist, x))
		printf("item: %d ditemukan dalam list.\n\n", x);
	else 
		printf("item: %d tidak ditemukan dalam list.\n\n", x);
	
	// demo hapus data berdasarkan index
	
	printf("remove item data at index: 0.\n\n");
	remove_at(&mylist, 0);
	
	printf("after remove item data at index: 0.\n");
	print_items(&mylist);
	
	idx = mylist.count-1;
	
	printf("remove item data at index: %d.\n\n", idx);
	remove_at(&mylist, mylist.count-1);
	
	printf("after remove item data at index: 0.\n");
	print_items(&mylist);
	
	printf("remove item data at index: 1.\n\n");
	remove_at(&mylist, 1);
	
	printf("after remove item data at index: 1.\n");
	print_items(&mylist);
	
	// demo hapus data by value
	
	printf("remove item data: 100 dari dalam mylist.\n\n");
	remove(&mylist, 100);
	printf("isi mylist setelah delete item data: 100.\n");
	print_items(&mylist);
	
	printf("remove item data: 1 dari dalam mylist.\n\n");
	remove(&mylist, 1);
	printf("isi mylist setelah delete item data: 1.\n");
	print_items(&mylist);
	
	printf("remove item data: 11 dari dalam mylist.\n\n");
	remove(&mylist, 11);
	printf("isi mylist setelah delete item data: 11.\n");
	print_items(&mylist);
	
	printf("remove item data: 3 dari dalam mylist.\n\n");
	remove(&mylist, 3);
	printf("isi mylist setelah delete item data: 3.\n");
	print_items(&mylist);
	
	return 0;
}
