/*
Name: Donal Mathew P T
Roll no: 20

question: 

Implement a Stack using arrays with the operations:
1.Pushing elements to the Stack.
2.Popping elements from the Stack
3.Display the contents of the Stack after each operation.

*/
#include <stdio.h>
#define CAPACITY 30

int stack[CAPACITY];
int top = -1;

void push(int val) {
	if (top >= CAPACITY) {
		printf("Stack Overflow!\n");
		return;
	}
	stack[++top] = val;
}

void pop() {
	if (top == -1) {
		printf("Stack Underflow!\n");
		return;
	}
	top--;
}

void display() {
	if (top != -1) {
		printf("Stack: ");
		for (int i = 0; i < top + 1; i++)
			printf("%d ", stack[i]);
		printf("\n");
	} else {
		printf("Empty Stack!\n");
	}
}

int main() {
	int choice, val, done = 0;

	printf("Choose form the following:\n");
	printf("1. Push\n2. Pop\n3. Stop\n");

	while (!done) {
		printf("Your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &val);
				push(val);
				display();
				break;
			case 2:
				pop();
				display();
				break;
			case 3:
				done = 1;
				printf("Done!\n");
				break;
			default:
				printf("Invalid input! Try again...\n");
		}
	}

	return 0;
}
