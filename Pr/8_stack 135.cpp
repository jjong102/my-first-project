// p.135 ������ ���� �̷ι���


#if 1

#include <stdio.h>

// �̷� ���� �׷����� 
// 2���� �迭 ���, char
// '1'�� ����Ǿ� ������, ��
// '0'�� ����Ǿ� ������, ����

// �̷��� ũ��, ���� 6ĭ, ���� 6ĭ
#define MAZE_SIZE 6
#define STACK_SIZE MAZE_SIZE*MAZE_SIZE

// row, column ��ǥ�� �����ϴ� ��������
typedef struct { // = ����ü == int�� ���� 
	int r;
	int c;
} LOC;

LOC stack[STACK_SIZE];
int top = -1;

char maze[MAZE_SIZE][MAZE_SIZE] = {
	
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},   // e : entrance
	{'1','0','0','0','1','1'},   
	{'1','0','1','0','1','1'},	
	{'1','0','1','0','0','x'},	 // x : esit
	{'1','1','1','1','1','1'}
};


// �̷θ� �̻ڰ� ������ִ� �Լ�
void printMaze(void) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

int isFull(void) {
	return (top == (STACK_SIZE - 1));
}

int isEmpty(void) {
	return (top == -1);
}

// push�� ��ǥ (_r, _c)�� �޾Ƽ�,
// ������ �� ���鸸 stack�� push�Ѵ�.
// ��('1'), ������ ��('.'), ���� ��ǥ���� ��� ����.
void push(int _r, int _c) {
	
	// ���� ��ǥ�� �Ÿ���
	if ((_r < 0) || (_c < 0)) {
		return;
	}
	// ��, ������ ��, �ɷ�����
	if ((maze[_r][_c] == '1') || (maze[_r][_c] == '.')) {
		return;
	}

	if (isFull()) {
		return;
	}

	LOC temp = { _r, _c };
	top++;
	stack[top] = temp;
	return;

}

LOC pop(void) {

	//���� ����
	if (isEmpty()) {
		LOC err_loc = { -1, -1 }; // ������ ����ٴ� �ǹ�
		return err_loc;
	}
	// �������
	LOC result = stack[top];
	top--;
	return result;
}


int main(void) {
	printMaze();

	LOC cur = { 1, 0 }; // ������ġ
	
	while (1) {
		// Ż�� ���� == x�� �����ϸ� ��
		if (maze[cur.r][cur.c] == 'x') {
			printf("�� ã�ҽ�, �����ͼ�\n");
			return 0;
		}

		// ������ ����ִ��� Ȯ��, ���� ����ٸ� ===> �����.
		if ((cur.r == -1) && (cur.c == -1)) {
			printf("�����!\n");
			return -1;
		}

		//���� �ٳబ���� ǥ��
		maze[cur.r][cur.c] = '.'; // ���� ���ڱ��� �����. �ٽ� ���� �ʱ� ����

		// ���, ������ ����
		printMaze();

		// ���� ��ġ���� �� �� �ִ� ������ ��� stack�� ���� �ִ´�.
		// ��� 4����, �����¿�
		push(cur.r - 1, cur.c);
		push(cur.r + 1, cur.c);
		push(cur.r, cur.c - 1);
		push(cur.r, cur.c + 1);

		// ���ÿ� ����� ��ǥ�� ������ ���� ��ġ�� ��´�.
		cur = pop();



	};

		return 0;
	
}
#endif