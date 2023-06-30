#include <stdio.h>
#define SZ 10
int stack[SZ];
int top = -1;


int isfull(void) {
	return (top == SZ - 1);
}

int isEmpty(void) {
	return (top == -1);
}

void push(int v) {
	if (isfull()) {
		return;
	}
	top++;
	stack[top] = v;
	return;
}

int pop(void) {
	if (isEmpty()) {
		return -999; //error
	}
	int res = stack[top];
	top--;
	return res;
}





int main(void) {

	
	return 0;
}