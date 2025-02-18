#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	const char *data;
	struct node *next;
} Node;


typedef struct linkedlist {
	
	Node *head;
	Node *tail;
	int count;
	
	linkedlist() {
		head = tail = NULL;
		count = 0;	
	}
	
	void add(const char *value) {
	}
	
	void insert(const char *value, int index) {
	}
	
	void display() {
	}
	
	bool contain(const char *value) {
	}

	int index_of(const char *value) {
	}
	
	void remove_at(int index) {
	}	

	void remove(const char *value) {
	}
	
	void replace_item_at(const char *value, int index) {
	}
		
	~linkedlist() {
		if (tail != NULL) tail->next = NULL;
		while (head != NULL) {
			Node *p = head;
			head = p->next;
			p->next = NULL;
			free(p);
		}
		count = 0;
	}	
	
} CircularLinkedList;


int main() {
	
	return 0;
}
