#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
	char data;
	node *next;
} Node;

typedef struct stack {
	
	Node *head;
	int   size;
	
	stack() {
		head = NULL;
		size = 0;
	}

	void push(char value) {
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->data = value;
		newNode->next = NULL;
		if (head == NULL) 
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	
	bool is_empty() {
		return head == NULL;
	}
	
	char top() {
		return head->data;
	}
	
	char pop() {
		char k = head->data;
		Node *p = head;
		head = p->next;
		p->next = NULL;
		free(p);
		size--;
		return k; 
	}
	
} Stack;

bool is_opr(char value) {
	switch ( value ) {
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
			return true;
	}
	return false;
}

int hirarki(char value) {
	switch (value) {
		case '^':
			return 3;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '+':
		case '-':
			return 1;
			break;
	}
}

char* konversi_to_postfix(const char *infix) {
	char *postfix = (char *)malloc(sizeof(char) * (strlen(infix)+1));
	Stack mystack;
	int idx = 0;
	for ( int i = 0 ; i < strlen(infix) ; i++ ) {
		char kar = infix[i];
		if (isspace(kar)) continue;
		if (kar == '(') { // jika kar => tanda kurung buka
			mystack.push(kar); 
		}
		else if (kar == ')') { // jika kar => tanda kurung tutup
			char t;
			do {
				t = mystack.pop();
				if (t != '(') postfix[idx++] = t;
			} while (t != '(');
		}
		else if (is_opr(kar)) { // jika kar => operator
			if ( mystack.is_empty()  
			     || mystack.top() == '(' 
					 || hirarki( mystack.top() ) < hirarki( kar ) ) {
				mystack.push(kar);
			}
			else {
				while ( !mystack.is_empty() && is_opr( mystack.top() )
				       && hirarki( mystack.top() ) >= hirarki( kar ) ) {
					postfix[idx++] = mystack.pop();
				}
				mystack.push(kar);
			}
		}
		else { // jika kar => operand
			postfix[idx++] = kar;
		}
	}	

	while ( !mystack.is_empty() ) {
		postfix[idx++] = mystack.pop();
	}
	
	postfix[idx] = '\0';
	
	return postfix;
}


int main() {
	const char *infix = "J + I - ( H * G + F ) / ( E ^ ( D - C ) * ( B + A ) )";
	printf("infix: %s -> postfix: %s\n", infix, konversi_to_postfix(infix));
	return 0;
}





