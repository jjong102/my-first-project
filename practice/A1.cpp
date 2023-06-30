#include <stdio.h>
#define SZ 5

int stack[SZ];
int top = -1;


void push(int _v) {
	if (SZ - 1 == top) {
		stack[0] = 0;
		for (int i = 0; i <= SZ - 1; i++) {
			stack[i] = stack[i + 1];
		}
		stack[top] = _v;
		return;
	}
	top++;
	stack[top] = _v;
	return;

}

int pop(void) {
	if (top == -1) {
		return -999;
	}
	
	int res = stack[top];
	top--;
	return res;
}



int main(void) {
	int v = 0;
	
	
	while (1) {
		scanf_s("%d ", &v);
		if (v == 0) {
			break;
		}

		else if (v == -1) {
			pop();
			break;
		}
		push(v);
	}

	
	printf("%d ", pop());
	
	
	return 0;
}