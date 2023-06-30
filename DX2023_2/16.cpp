#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* left;
	node* right;
}node;

node* root = 0;

typedef struct combo {
	node* parent;
	node* me;
};

// ���� ������ ���ϸ鼭 ��������. �������� �־����
void addToBST(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->left = _new->right = 0;

	if (root == 0) {
		root = _new;
		return;
	}

	node* temp = root;
	while (1) {
		if (temp->data < _new->data) {
			if (temp->right == 0) {
				temp->right = _new;
				return;
			}
			else {
				temp = temp->right;
			}
		}
		else {
			if (temp->left == 0) {
				temp->left = _new;
				return;
			}
			else {
				temp = temp->left;
			}
		}
		
	}
}


// �ϴ� ������ �׸��� ���� �߸�Ǿ���? �׷� �ٽ� ���� �ļ� ���ƿ�
combo findcombo(int _v) {
	node* spear = root;
	node* parent = 0;

	while (1) {
		if (spear == 0) {
			combo res = { 0,0 };
			return res;
		}
		
		if (spear->data == _v) {
			combo res = { parent, spear };
			return res;
		}

		else if (spear->data > _v) {
			parent = spear;
			spear = spear->left;
		}

		else {
			parent = spear;
			spear = spear->right;
		}
	}



}



void delFromBST(int _v) {
	combo res = findcombo(_v); // ���� ��带 ã�� �� ������ �˰���?


	if (res.me == 0) {
		return;
	}
	// 1. ���ڽ��� ���
	if (res.me->left == 0 && res.me->right == 0) {
		if (res.parent == 0) {
			root = 0;
			free(res.me);
			return;
		}
		else {
			if (res.parent->left == res.me) {
				res.parent->left = 0;
			}
			else {
				res.parent->right = 0;
			}
			free(res.me);
			return;
		}
	}
	else if (res.me->left != 0 && res.me->right != 0) {
		node* spear = res.me->right;
		while (1) {
			if (spear->left == 0) {
				break;
			}
			spear = spear->left;
		}

		int temp = spear->data;
		delFromBST(temp);
		res.me->data = temp;
		return;


	}
	else {
		if (res.me->left != 0) {
			if (res.parent == 0) {
				root = res.me->left;
				free(res.me);
				return;
			}

			else {
				if (res.parent->left == res.me) {
					res.parent->left = res.me->left;
				}
				else {
					res.parent->right = res.me->left;
				}
				free(res.me);
				return;
			}
		}
		else {
			if (res.parent == 0) {
				root = res.me->right;
				free(res.me);
				return;
			}
			else {
				if (res.parent->left == res.me) {
					res.parent->left = res.me->right;
				}
				else {
					res.parent->right = res.me->right;
				}
				free(res.me);
				return;
			}
		}

	}
}






int main(void) {
	addToBST(10);
	addToBST(20);
	addToBST(5);


	return 0;
}
