#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

node* root = 0;

typedef struct combo {
	struct node* parent;
	struct node* me;
}combo;

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
		if (temp->data < _v) {
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


int termineralnode_count(node* _cur) {
	if (_cur == 0) {
		return 0;
	}
	else if (_cur->left == 0 && _cur->right == 0) {
		return 1;
	}
	return (termineralnode_count(_cur->left) + termineralnode_count(_cur->right));
}

combo findNodeCombo(int _v) {
	node* temp = root;
	node* parent = 0;
	while (1) {
		if (temp == 0) {
			combo res = { 0, 0 };
			return res;
		}

		else if (temp->data == _v) {
			combo res = { parent ,temp };
			return res;
		}

		else if (temp->data > _v) {
			parent = temp;
			temp = temp->left;
		}
		else {
			parent = temp;
			temp = temp->right;
		}
	}
}


void delFromBST(int _v) {
	combo res = findNodeCombo(_v);

	if (res.me == 0) {
		return;
	}
 
	
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

	else if (res.me->left != 0 && res.me->right != 0) {
		node* temp = res.me->right;
		while (1) {
			if (temp->left == 0) {
				break;
			}
			temp = temp->left;
		}

		int result = temp->data;
		delFromBST(result);
		res.me->data = result;
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
		else{
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

void in_order(node* _cur) {
	if (_cur == 0) {
		return;
	}

	in_order(_cur->left);
	printf("%d ", _cur->data);
	in_order(_cur->right);
}


int main(void) {
	int v = 0;
	while (1) {
		scanf_s("%d", &v);
		if (v == 0) {
			break;
		}
		addToBST(v);
	}

	while (1) {
		scanf_s("%d", &v);
		if (v == -1) {
			in_order(root);
			return 0;
		}
		else if (v == -2) {
			printf("%d", termineralnode_count(root));
			return 0;
		}

		delFromBST(v);
	}
}