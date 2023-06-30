#include<stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	node* left;
	node* right;
};

node* root = 0;

void addToBST(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->left = _new->right = 0;

	// tree에 아무것도 없을때
	if (root == 0) {
		root = _new;
		return;
	}

	node* temp = root;
	while (1) {
		if (temp->data > _new->data) {
			if (temp->left == 0) {
				temp->left = _new;
				break;
			}
			temp = temp->left;
		}

		else {
			if (temp->right == 0) {
				temp->right = _new;
				break;
			}
			temp = temp->right;
		}
	}
	return;
}

void in_order_traversal(node* _cur) {
	if (_cur == 0) {
		return;
	}

	in_order_traversal(_cur->left);
	printf("%d\n", _cur->data);
	in_order_traversal(_cur->right);

}

#define ST_SZ 10

node* stack[ST_SZ];
int top = -1;

void push(node* _cur) {
	if (top == ST_SZ - 1) {
		return;
	}

	top++;
	stack[top] = _cur;
	return;
}

node* pop(void) {
	if (top == -1) {
		return 0;
	}

	node* res = stack[top];
	top--;
	return res;
}

void nonrecirsion_inorder(node* _cur) {
	if (_cur == 0) {
		return;
	}
	while (1) {
		while (1) {
			if (_cur != 0) {
				push(_cur);
				_cur = _cur->left;
			}
			else {
				break;
			}
		}
		_cur = pop();
		if (_cur == 0) {
			break;
		}
		printf("%d\n", _cur->data);
		_cur = _cur->right;

	
	}
	return;

}

#define Q_SZ 10

node* que[Q_SZ];
int front = 0;
int rear = 0;

void enqueue(node* _cur) {
	if (front == (rear + 1) % Q_SZ) {
		return;
	}

	que[rear] = _cur;
	rear = (rear + 1) % Q_SZ;
	return;
}

node* dequeue(void) {
	if (rear == front) {
		return 0;
	}

	node* res = que[front];
	front = (front + 1) % Q_SZ;
	return res;
}


void level_order(node* _cur) {
	if (_cur == 0) {
		return;
	}
	enqueue(_cur);
	while (1) {
		if (front == rear) {
			break;
		}
		_cur = dequeue();
		printf("%d\n", _cur->data);
		if (_cur->left != 0) {
			enqueue(_cur->left);
		}
		if (_cur->right != 0) {
			enqueue(_cur->right);
		}
	}
}

int which_is_bigger(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int height(node* _cur) {
	if (_cur == 0) {
		return 0;
	}
	return (1 + which_is_bigger(height(_cur->left), height(_cur->right)));
}

int get_count(node* _cur) {
	if (_cur == 0) {
		return 0;
	}

	return (1 + get_count(_cur->left) + get_count(_cur->right));
}

int get_terminal_node_count(node* _cur) {
	if (_cur == 0){
		return 0;
	}
	else if (_cur->left == 0 && _cur->right == 0) {
		return 1;
	}


	return (get_terminal_node_count(_cur->left) + get_terminal_node_count(_cur->right));
}


int main(void) {
	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(5);


	nonrecirsion_inorder(root);

	return 0;
}