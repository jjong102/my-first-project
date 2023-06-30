#include <stdio.h>
#include <stdlib.h>


// BST�� ��带 ǥ��
struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct combo {
	struct node* parent;
	struct node* me;
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

// BST�� ��� ����

// 1. ���ڽ� ��� (terminal node) ������ ����.
//		�ٸ�, �θ� ��常 ������ �޴´�. �ش� link = null�� ����
//		!!! ���ڽ� ��� == root
//				===> root�� null�� ��ȯ

// 2. Ȭ (1��)�ڽ�, 
//		�ڽĿ��� �ڱ� �ڸ��� �����ְ�, ���� �θ𿡰� '���ڽ�'�� ��������ش�.
//		** ���� �θ��� '� �ڽ�'���� �� ����ߴٰ�, �׷��� '�� �ڽ�' �������ش�.
//		!!! Ȭ�ڽ� ��尡 == root,
//				root�� �Ͽ��� ���� �ڽ��� ����Ű�� �Ѵ�.

// 3. ��(2��) �ڽ�
//		���� ���ȿ��� ���� ū ��尡 �ö�ͼ� ��ü,
//		������ ���ȿ��� ���� ���� ��尡 �ö�ͼ� ��ü,
//		!!! ���ڽ� ��� == root,
//				���ž���...


// �� _v�� ���� ���� parent ��带 ã�Ƽ�,
// ������ ���� �����͸� struct combo�� ���� ��ȯ�Ѵ�.
//		parent: _v�� ���� ����� �θ� ��� (�θ� ������ null�� ��ȯ)
//		me  : _v�� ���� ���              ( _v�� ���� ��尡 ���� ���, null)
struct combo findNodeCombo(int _v) { //����� ���� pointer�ϰ� �θ� ���� pointer 2���� �Ѱ������. --> struct �̿�
	struct node* spear = root;
	struct node* parent = 0; // root(me)�� �θ�

	while (1) {

		if (spear == 0) {
			struct combo res = { 0, 0 };
			return res;
		}

		if (spear->data == _v) { // _v�� ���� ��带 ã�� ���,
			struct combo res = {parent, spear};
			return res;
		}

		else if (spear->data < _v) { //���������� Ÿ�� ����������.
			parent = spear;
			spear = spear->right;
		}

		else { //�������� Ÿ�� ���� ���� ���,
			parent = spear;
			spear = spear->left;
		}

	}
}

// �� _v�� ���� ��带 ����
void delFromBST(int _v) {

	struct combo res = findNodeCombo(_v); //_v�� ���� ��带 ã�´�.

	if (res.me == 0) { // _v�� �����Ƿ� ����, thank you
		return;
	}

	// 1. ���ڽ�
	if (res.me->left == 0 && res.me->right == 0) {
		// ����,root���� �Ǻ�
		if (res.parent == 0) { // ���� root
			root = 0;
			free(res.me);
			return;
		}
		else {
			if (res.parent->left == res.me) { // ���� �θ��� ���ڽ�
				res.parent->left = 0;
			}
			else { // ���� �θ��� �����ڽ�
				res.parent->right = 0;
			}
			free(res.me);
			return;
		}
	}
	

	// 3. ���ڽ�
	else if (res.me->left != 0 && res.me->right != 0) {
		// �ϴ� �İ��ڸ� ã�´�.
		struct node* spear = res.me->right;
		while (1) {
			if (spear->left == 0) {
				break;
			}
			spear = spear->left;
		}
		// �� ��Ȳ���� spear�� �İ��ڸ� ����Ű�� �ִ�.
		// �İ谡 ���� �ӽ� ������ ���´�.
		int temp = spear->data;
		// �İ��ڸ� ����������.
		delFromBST(temp);
		// �ӽ����� ���� me�ڸ��� ä���.
		res.me->data = temp;
		return;
	}


	// 2. Ȭ�ڽ�
	else {
		// �ϴ�, ���� ���ڽ� ������ �ִ��� Ȯ��
		if (res.me->left != 0) { // ���� �ڽ� �ϳ��� ������ ����.
			// ���� root�� ���
			if (res.parent == 0) { // root�� ����
				root = res.me->left;
				free(res.me);
				return;
			}
			else { // ���� root�� �ƴ�.
				if (res.parent->left == res.me) { // me�� parent�� left
					res.parent->left = res.me->left;
				}
				else { // me�� parent�� right
					res.parent->right = res.me->left;
				}
				free(res.me);
				return;
			}
		}
		else { // �����ڽ� �ϳ��� ������ ����.
			// ���� root�� ���
			if (res.parent == 0) { // root�� ����
				root = res.me->right;
				free(res.me);
				return;
			}
			else { // ���� root�� �ƴ�.
				if (res.parent->left == res.me) { // me�� parent�� left
					res.parent->left = res.me->right;
				}
				else { // me�� parent�� right
					res.parent->right = res.me->right;
				}
				free(res.me);
				return;
			}

		}

	}
	
	

	




}

void inorder_traversal(struct node* _cur) {
	if (_cur == 0) {
		return;
	}
	inorder_traversal(_cur->left);
	printf("%d\n", _cur->data);
	inorder_traversal(_cur->right);
}

int main(void) {

	//  20
	// 10 30
	// 5   40
	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(5);
	
	// ���ڽ� �����
	delFromBST(10);
	//delFromBST(40);

	// Ȭ�ڽ� �����
	//delFromBST(30);

	//���ڽ� �����
	//delFromBST(20);

	// ���� �ڽ� �����
	delFromBST(100);


	inorder_traversal(root);


	//struct combo res = findNodeCombo(5);
	//printf("%d    %d\n", res.me->data, res.parent->data); // if) 5�� ã�´ٸ� 5, 10
	//printf("%d    %d\n", res.me->data, (res.parent == 0)); // if 20 root 20, 1
	//printf("%d    %d\n", (res.me == 0), (res.parent == 0)); // if 100 1, 1
	return 0;
}
