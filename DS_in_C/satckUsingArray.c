/* Author: HelalMajeed, Date: 2022-Aug-24 */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int stack[100]; // Assume Max Length Is 100
int top = - 1;

void push(int value) {
	assert(top < 100); // Never Gonna Cross The Max Length
	++top;
	stack[top] = value;
}

void getTop() {
	assert(top >= 0); // To Make Sure That The Stack Is Not Empty
	printf("%d\n", stack[top]);
}

void pop() {
	assert(top >= 0);
	--top;
}

bool isEmpty() {
	return top == -1;
}

void printStack() {
	for(int i=0; i<=top; i++) {
		printf("%d\n", stack[i]);
	}
}

int main() {

	push(0);
	push(1);
	push(2);
	push(3);

	puts("Stack is:");
	printStack();

	printf("top is ");
	getTop();
	
	if(isEmpty()) printf("Stak is empty\n");
	else printf("Stak is not empty\n");

	return 0;
}

// NOTICE: That every thing here takes O(1)
// Except the printing takes O(n)
