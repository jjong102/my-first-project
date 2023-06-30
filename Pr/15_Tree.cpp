// chap.8 , Tree, p. 254

// stack, queue, SLL, DLL
// --> ����

// ������ ����
// Tree�� ������ ������ ǥ���ϴ� ��ǥ�� �����ͱ���
// Root Node : Tree���� ó�� �����ϴ� Node
// sub_Tree : Tree �ؿ� �ִ� �� �ٸ� ���� Tree
// edge : node�� node�� �̾��ִ� ��
// ~ p.255

// Parent node : node�� ���� node
// Child node : node�� ���� node
// Sibling node : node�� ���� ������ �ִ� node
// ~ p. 256 ��ܺ�

// terminal node (����, �ܸ� ���) : child node�� ���� node
// non-terminal node (��ܸ� ���) : chile node�� �ִ� node
// child node ���� ������ ����,
// p.256

// degree of a node(����) p.256
// ����� �ڽĳ�� �ִ� ����
// degree of tree
// == max(degree of a node)
//   0        ex) degree of node == 3
// 0 0 0

// Height of a tree (Ʈ���� ����), p.256
// == max(level)
// Level (����) : ���� ���� = ���� ��(level)

// p.256 ������ ��� == Forest (�������� ����)
//					== set of trees

// p.257, Ʈ���� ����
// ---> degree of a tree == 2 (�ڽ��� ���� �ִ� 2��)
//		=== binary tree
//		=== ���� Ʈ��

// p.258 
// left subtree, right subtree (binary tree�̱� ������ �̷� ǥ���� ����)

// p.259 ����Ʈ���� ����

// 1. n���� ��带 ���� ����Ʈ������
//		edge�� ������ n-1����.
//		Ʈ������ ��� ���� �θ�� ���� edge�� ������.
//		��, root node�� ����

// 2. (p.260)
//	���̰� h�� ���� Ʈ������
//		��尡 �ּ� h�� �ְ�,
//			�ִ� 2^h - 1 ��ŭ �ִ�.

// 3. (p. 260)
//	n���� ��带 ������ ����Ʈ���� ���̴�
//	�ִ� n�̰ų�, 
//	�ּ� log_2(n+1)
//		n <= 2^h -1
//		n + 1 <= 2^h
//		log_2(n+1) <= h

// p.261
// ����Ʈ���� �з�

// 1. full binary tree : node�� �˲�ä�� tree
// 2. complete binary tree : ������� �˲� ä��� complete

// tree --> binary tree --> binary search tree (BST) : �˻��� ����ȭ�� Tree
//							���ʿ� �ִ� subTree�� ���� �۰�, �����ʿ� �ִ� subTree�� ���� ũ��.  - 2 - 
//							�� level�� �����ö� ����, �˻����� �ݶ��� ����. 					1	  3

#include <stdio.h>
#include <stdlib.h>


// BST�� ��带 ǥ��
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// root node�� ����Ű�� ������
struct node* root = 0;

void addToBST(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->left = 0;
	_new->right = 0;
	_new->data = _v;

	// BST�� ��带 �߰�
	// 1. BST�� ���� ����ִ� ���
	if (root == 0) {
		root = _new;
		return;
	}

	// 2. BST�� ���� �ִ� ���,
	// �̶��� �ڱ� ��ġ�� ã�ư��� �Ѵ�. ��𰡼� �پ�� �ϴ���
	// root�� ������ �� ������, ������ ������ �ʿ�
	struct node* spear = root;

	while (1) {

		if (spear->data < _new->data) { // ���� ���������� �����ϴµ�,,,
			// 1. �� �ڸ��� �����,
			if (spear->right == 0) {   // ���ڸ� �ְ� ��!
				spear->right = _new;
				return;
			}
			// 2. �� ������ �� �ڸ��� �����ϰ� �־, �� ������ ���� �ϴ� ��Ȳ. 
			else {
				spear = spear->right;
			}
		}

		else { // �������� �����ϴµ�
			if (spear->left == 0) { // ���ڸ��� �ְ� ��!
				spear->left = _new;
				return;
			}
			else {
				spear = spear->left;
			}
		}



	}
}

// Traversal (�湮) : �� �� �ִ� node�� �ѹ��� �� �湮 (�ߺ�x)
// 3���� �湮 ���, p. 236, ���� Ʈ���� ��ȸ (traversal)
// 1. pre-order traversal (���� ��ȸ) �ڱ� - l - r         4      4,2,1,5
// 2. in-order traversal (���� ��ȸ) l - �ڱ� - r        2  5     1,2,4,5 (�������� ����)
// 3. post-order traversl (���� ��ȸ) l - r - �ڱ�      1         1,2,5,4
//

void traversal_inorder(struct node* _cur) {
	if (_cur == 0) {
		return;
	}
	traversal_inorder(_cur->left);
	printf("%d\n", _cur->data);
	traversal_inorder(_cur->right);

}

void traversal_preorder(struct node* _cur) {
	if (_cur == 0) {
		return;
	}
	printf("%d\n", _cur->data);
	traversal_preorder(_cur->left);
	traversal_preorder(_cur->right);
}

void traversal_postorder(struct node* _cur) {
	if (_cur == 0) {
		return;
	}
	traversal_preorder(_cur->left);
	traversal_preorder(_cur->right);
	printf("%d\n", _cur->data);
	
}


// recursion�� ������!  p.277
// ����Լ� ���� inorder�� �����غ���!
// ���?
//	 letf�켱���� �������� null�� �ƴϸ� push, null�̸� pop 
//	 right�� �������鼭 left ����, right ���� stack�� ��������� ��!
#define STACK_SZ 10
struct node* stack[STACK_SZ]; 
int top = -1; 


// ���⼭ ���� ������.....
void push(struct node* _cur) {
	if (top == STACK_SZ - 1) {
		return;
	}
	top++;
	stack[top] = _cur;
	return;
}

struct node* pop(void) {
	if (top == -1) {
		return 0;
	}
	struct node* temp = stack[top];
	top--;
	return temp;
}

// ����������� inorder traversal�� ����
void nonrecurvise_inorder(struct node* _cur) {

	while (1) {
		while (1) { //�������� �������鼭 push
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


// ���� ��ȸ p.279
#define	Q_SZ 10 
struct node* que[Q_SZ]; 
int front = 0;
int rear = 0;

void enqueue(struct node* _cur) {
	if ((rear + 1) & Q_SZ == front) {
		return;
	}

	que[rear] = _cur;
	rear = (rear + 1) % Q_SZ;
	return;
}

struct node* dequeue(void) {
	if (front == rear) {
		return 0;
	}
	struct node*result = que[front];
	front = (front + 1) % Q_SZ;
	return result;

}

void level_order(struct node* _cur) {
	if (_cur == 0) {
		return; // BST�� �ƹ��͵� ���� ���
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

 
// ���� ���ϱ�, p.289
// �����̴� �������̴� Űū�� +1�ϸ� Ű���� (recursion)
int which_is_bigger(int a, int b) {

	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int get_height(struct node* _cur) {
	if (_cur == 0) { // NULL
		return 0; // height
	}
	return (1 + which_is_bigger(get_height(_cur->left), get_height(_cur->right)));
}


// node ���� ���ϱ�, p.288 
int get_node_count(struct node* _cur) {
	if (_cur == 0) {
		return 0;
	}

	return 1 + get_node_count(_cur->left) + get_node_count(_cur->right);
}

//p. 289, �ܸ� ��� ���� ���ϱ� (�ڽ��� ���� node�� ���� ���ϱ�)
int get_terminalnode_count(struct node* _cur) {
	// Ż�� ����
	if (_cur == 0) {
		return 0;
	}
	else if(_cur->left == 0 && _cur->right == 0) {
		return 1;
	}


	return get_terminalnode_count(_cur->left) + get_terminalnode_count(_cur->right);
}


// p. 283
// 8.7 Ʈ���� ����, ���� Ʈ�� ó��
// �׸� 8-32
// post order�� �̿��ϸ� posefix�ٷ� ����
// -   === abc*-
//a *
//  b c

// p.289





int main(void) {
	
	//  20
	// 10 30
	// 5   40
	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(5);

	//printf("%d\n", (root->data == 20));
	//printf("%d\n", (root->left->data == 10));
	//printf("%d\n", (root->right->data == 30));
	//printf("%d\n", (root->left->left->data == 5));
	//printf("%d\n", (root->right->right->data == 40));
	struct node* spear = root;

	//traversal_inorder(spear);
	//traversal_preorder(spear);

	nonrecurvise_inorder(root);

	// level_order(root); // ������ �Ʒ���, ���ʿ��� ����������

	/*printf("height = %d�Դϴ���~!\n", get_height(root));
	printf("terminal node count�� ������ %d�Դϴ���~!\n", get_terminalnode_count(root));*/
	return 0;
}

// skewed BST : SLL�� �Ȱ���, ��� ������ �Ҿ��������
// 
// 5
//  10
//   15
//    20









