#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* left;
	node* right;
}node;

typedef struct combo {
	node* parent;
	node* me;
}combo;

node* root = 0;

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
		if (temp->data > _new->data) {
			if (temp->left == 0) {
				temp->left = _new;
				return;
			}
			temp = temp->left;
		}

		else {
			if (temp->right == 0) {
				temp->right = _new;
				return;
			}
			temp = temp->right;
		}
	}
}

combo findNodeCombo(int _v) {
	node* spear = root;
	node* parent = 0;

	while (1) {
		if (spear == 0) {
			combo res = { 0,0 };
			return res;
		}

		else if (spear->data == _v) {
			combo res = { parent, spear };
			return res;
		}

		else {
			if (spear->data > _v) {
				parent = spear;
				spear = spear->left;
			}
			else {
				parent = spear;
				spear = spear->right;
			}
		}
	}
}

void delFromBST(int  _v) {
	combo res = findNodeCombo(_v);

	if (res.me == 0) {
		return;
	}

	
	while (1) {
		//1. 무자식
		if (res.me->left == 0 && res.me->right == 0) {
			if (res.parent == 0) {
				root = 0;
				free(res.me);
				return;
			}
			else {
				if (res.parent->right == res.me) {
					res.parent->right = 0;
				}
				else {
					res.parent->left = 0;
				}
				free(res.me);
				return;
			}
		}
		//2. 쌍자식
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
		//3. 홑자식
		else {
			if (res.me->right != 0) {
				if (res.parent == 0) {
					root = res.me->right;
					free(res.me);
					return;
				}
				else if (res.parent->left == res.me) {
					res.parent->left = res.me->right;
				}
				else {
					res.parent->right = res.me->right;
				}
				free(res.me);
				return;
			}
			else {
				if (res.parent == 0) {
					root = res.me->left;
					free(res.me);
					return;
				}
				else if (res.parent->left == res.me) {
					res.parent->left = res.me->left;
				}
				else {
					res.parent->right = res.me->left;
				}
				free(res.me);
				return;
			}
		}

	}


}

void traversal_inorder(node* _cur) {
	if (_cur == 0) {
		return;
	}
	traversal_inorder(_cur->left);
	printf("%d\n", _cur->data);
	traversal_inorder(_cur->right);
}

void traversal_preorder(node* _cur) {
	if (_cur == 0) {
		return;
	}
	printf("%d\n", _cur->data);
	traversal_preorder(_cur->left);
	traversal_preorder(_cur->right);
}

void traversal_postorder(node* _cur) {
	if (_cur->data) {
		return;
	}
	traversal_postorder(_cur->left);
	traversal_postorder(_cur->right);
	printf("%d\n", _cur->data);
}


int main(void) {

	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(5);

	// 무자식 지우기
	delFromBST(10);
	//delFromBST(40);

	// 홑자식 지우기
	//delFromBST(30);

	//쌍자식 지우기
	//delFromBST(20);

	// 없는 자식 지우기
	delFromBST(100);


	traversal_inorder(root);


	return 0;
}