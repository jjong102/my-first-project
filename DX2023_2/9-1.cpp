// stack 다시 구현
// 필요한 함수 4가지

#if 0
#include <stdio.h>
#define STACK_SZ 20


int stack[STACK_SZ];
int top = -1;


int isEmpty(void) {
	return (top == -1);
}


int isFull (void){
	return (top == STACK_SZ - 1);
}

void push(int _v) {
	if (isFull()) {
		printf("stack is full.\n");
		return;
	}
	top++;
	stack[top] = _v;

	return;
}

int pop(void) {
	if (isEmpty()) {
		printf("stack is empty.\n");
		return -999;
	}

	int temp = stack[top];
	top--;
	return temp;
}



int main(void) {
	
	push(1);
	push(2);
	push(3);

	
	pop();
	printf("%d\n", pop());
	
	return 0;
}
#endif