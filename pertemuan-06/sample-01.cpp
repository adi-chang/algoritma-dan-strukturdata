#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	
	int *data;
	int  capacity;
	int  size; 
	
	stack(int max) {
		capacity = max;
		size = 0;
		data = (int*)malloc(sizeof(int)*capacity);
	}
	
	bool is_empty() { 
		return size == 0;
	}
	
	bool is_full() {
		return size == capacity;
	}
	
	void push(int value) {
		if ( !is_full() ) {
			data[size++] = value;
		}
		else {
			printf("push: stack is full ...\n");
		}
	}
	
	int top() {
		if ( !is_empty() ) 
			return data[size-1];
		return -1;
	}
	
	int pop() {
		if ( !is_empty() ) 
			return data[--size];
		return -1;
	}
	
	void display() {
		printf("stack items [top to bottom] [size: %d] : ", size);
		if ( !is_empty() ) {
			for ( int i = size-1; i >= 0; i--) 
				printf("%d, ", data[i]);
			printf("\n");
		}
		else 
			printf("stack is empty ...\n");
	}
	
	~stack() {
		free(data);
	}
	
} Stack;


int main() {

	Stack mystack(10);
	
	mystack.display();
	
	for ( int i = 1 ; i <= 10 ; i++ ) {
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
