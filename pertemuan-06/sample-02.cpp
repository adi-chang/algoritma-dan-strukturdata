/*
	*** implementasi stack dengan linkedlist
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node *next;
} Node;

typedef struct stack {
	
	Node *head;
	int  size; 
	
	stack() { // constructor
		head = NULL;
		size = 0;
	}
	
	bool is_empty() { 
		return size == 0;
//		return head == NULL;
	}
	
	void push(int value) {
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->data = value;
		newNode->next = NULL;
		if ( head == NULL ) 
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;			
		}
		size++;
	}
	
	int top() {
		if ( !is_empty() ) 
			return head->data;
		return -1;
	}
	
	int pop() {
		int x = -1;
		if ( !is_empty() ) {
			Node *p = head;
			head = p->next;
			p->next = NULL;
			x = p->data;
			free(p);
			size--;
		}
		return x;
	}
	
	void display() {
		printf("stack items [top to bottom] [size: %d] : ", size);
		if ( !is_empty() ) {
			Node *p = head;
			while ( p != NULL ) {
				printf("%d, ", p->data);
				p = p->next;
			}
			printf("\n");
		}
		else 
			printf("stack is empty ...\n");
	}
	
	~stack() { // destructor
		while ( head != NULL) {
			Node *p = head;
			head = p->next; 
			p->next = NULL;
			free(p);
		}
	}
	
} Stack;



int main() {

	Stack mystack;
	
	mystack.display();
	
	for ( int i = 1 ; i <= 15 ; i++ ) {
		printf("push item: %d to stack.\n", i);
		mystack.push(i);
	}
	
	mystack.display();
	
	printf("top of stack item: %d\n", mystack.top());
	
	printf("pop stack item: %d\n", mystack.pop());
	printf("top of stack item: %d\n", mystack.top());
	
	printf("pop stack item: %d\n", mystack.pop());
	printf("top of stack item: %d\n", mystack.top());
	
	while ( !mystack.is_empty() ) {
		printf("pop stack item: %d\n", mystack.pop());
		if ( !mystack.is_empty() ) printf("top of stack item: %d\n", mystack.top());
	}
	
	return 0;
}
