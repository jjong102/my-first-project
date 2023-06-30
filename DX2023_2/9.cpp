// postfix
// 숫자면 스택에 집어 넣고
// 연산자면, 스택에서 숫자 두개 꺼내서 계산 후 다시 스택으로

// 들어오는 숫자와 연산자 한정

#if 0
#include <stdio.h>
#define STACK_SZ 20

// 스택을 구현
// empty, full, push, pop 4가지 함수가 필요
int stack[STACK_SZ];
int top = - 1;

int isEmpty() {
	return ((top == -1));
}

int isFull() {
	return ((top == STACK_SZ - 1));
}

void push(int _p) {
	if (isFull()) {
		return;
	}
	top++;
	stack[top] = _p;
	return;
}

int pop() {
	if (isEmpty()) {
		return -999;
	}
	int result = stack[top];
	top--;
	return result;
}


int clc_exr(int op, int v1, int v2) {

	switch (op) {
	case '+' :
		return (v1 + v2);
	case '-':
		return (v2 - v1);
	case '*':
		return (v1 * v2);
	case '/':
		return (v2 / v1);
	}
}


int main(void) {
	char postfix[] = "235*+";
	int idx = 0;

	while (postfix[idx] != '\0') {
		int i = postfix[idx];
		if (i >= '0' && i <= '9') {
			push((int)(i - '0')); // casting 부분 빼기 아이디어 확인!
		}
		else {
			int v1 = pop();
			int v2 = pop();
			int num = clc_exr(i, v1, v2);	
			push(num);
		}
		idx++;
	}

	printf("연산 결과는 %d 입니당아아아!!\n", pop());

	return 0;
}
#endif