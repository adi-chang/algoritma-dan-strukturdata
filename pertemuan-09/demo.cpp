#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	const char *item;
	node *next;
} Node; 

typedef struct queue {
	Node *head;
	Node *tail; 
	int size;
	
	queue() {
		head = tail = NULL;
		size = 0;
	}	
	
	bool is_empty() {
		return head == NULL;
	}	
	
	void enqueue(const char *value) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->item = value;
		newNode->next = NULL;
		if (head == NULL)
			head = tail = newNode;
		else {
			tail->next = newNode;
			tail = newNode;
		}
		++size;
	}
	
	const char* dequeue() {
		const char *temp = head->item;
		Node *p = head;
		head = p->next;
		p->next = NULL;
		free(p);
		size--;
		return temp;
	}
	
	void display() {
		printf("queue items [count = %d] : ", size);
		if (is_empty())
			printf("empty ...\n");
		else {
			Node *p = head;
			while ( p != NULL ) {
				printf("%s ", p->item);
				p = p->next;
			}
			printf("\n");
		}
	}
	
} Queue; 

int main() {
	
	Queue myqueue;
	
	// cek - display , item dalam queue ? 
	myqueue.display();
	
	const char *list_nama[] = { 
		"Budi", 
		"Iwan", 
		"Gunawan", 
		"Susi", 
		"Tini",
		"Juli",
		"Robert"};
		
	int n = 7;
	
	// mendaftarkan item data ke dalam antrian (enqueue)
	printf("\n");
	for ( int i = 0 ; i < n ; i++ ) {
		printf("enqueue item: %s\n", list_nama[i]);
		myqueue.enqueue(list_nama[i]);
		myqueue.display();
	}
	printf("\n");
	
	// drop item dari dalam antrian (dequeue)
	
	printf("\n");
	while ( !myqueue.is_empty() ) {
		printf("dequeu item: %s\n", myqueue.dequeue());
		myqueue.display();
	}
	printf("\n");
	
	
	
	
	return 0;
}
