#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct set {
	
	struct node *head;
	struct node *tail;
	int size;
	
	set() {
		head = tail = NULL;
		size = 0;
	}
	
	bool contain(int elemen) {
		if ( head == NULL )
			return false;
		else {
			struct node *p = head; 	
			while ( p != NULL ) {
				if ( p->data == elemen) return true;
				p = p->next;
			}
			return false;
		}
	}
	
	void add(int elemen) {
		if ( !contain(elemen) ) {
			struct node *newNode = (struct node*)malloc(sizeof(struct node));
			newNode->data = elemen;
			newNode->next = NULL;
			if (head == NULL) 
				head = tail = newNode;
			else {
				tail->next = newNode;
				tail = newNode;
			}			
			size++;
		}		
	}
	
	void update(int arr[], int n) {
		for ( int i = 0 ; i < n ; i++ ) {
			add(arr[i]);
		}
	}
	
	struct set Union ( struct set another ) {
		struct set ss;
		struct node *p = head;
		while ( p != NULL ) {
			ss.add(p->data);
			p = p->next;
		}
		p = another.head;
		while ( p != NULL ) {
			ss.add(p->data);
			p = p->next;
		}
		return ss;
	}
	
	struct set Intersection ( struct set another ) {
		struct set ss;
		struct node *p = head;
		while ( p != NULL ) {
			struct node *q = another.head;
			while ( q != NULL ) {
				if ( p->data == q->data ) {
					ss.add(p->data);
					break;
				}
				q = q->next;
			}
			p = p->next;
		}
		return ss;
	}
	
	int get_minimum() {
		if ( size > 1 ) {
			int min = INT_MAX;
			struct node *p = head;
			while ( p != NULL ) {
				if ( min > p->data ) min = p->data;
				p = p->next;
			}	
			return min;
		}
		printf("sorry, no minimum value ...\n");
	}
	
	int get_maximum() {
		if ( size > 1 ) {
			int max = INT_MIN;
			struct node *p = head;
			while ( p != NULL ) {
				if ( max < p->data ) max = p->data;
				p = p->next;
			}	
			return max;
		}
		printf("sorry, no maximum value ...\n");
	}
	
	void display() {
		printf("Set Items: \n");
		if ( head == NULL ) 
			printf("empty ...\n");
		else {
			struct node *p = head;
			int idx = 0;
			while ( p != NULL ) {
				printf("%6d ", p->data);
				p = p->next;
				if ( ++idx % 10 == 0) printf("\n");
			}
			printf("\n");
		}
	}
	
	void remove(int elemen) {
		if ( contain(elemen) ) {
			// remove
			struct node *p = head; 
			if ( head->data == elemen ) { 
				head = p->next;
				p->next = NULL;
				free(p);
			}
			else { 
				while ( p->next != NULL && p->next->data != elemen )
					p = p->next;
				struct node *q = p->next;
				p->next = q->next;
				q->next = NULL;
				free(q);
			}
			size--;
		}
		else 
			printf("elemen: %d tidak ditemukan ...\n", elemen);
	}
	
};

typedef struct set Set;






