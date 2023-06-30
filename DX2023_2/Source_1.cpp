










#include <stdio.h>
#include <stdlib.h>

#define STACK_SZ 10


struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = 0;

void addToBST(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->left = 0;
    _new->right = 0;
    _new->data = _v;

            if (root == 0) {
        root = _new;
        return;
    }

                struct node* spear = root;

    while (1) {
        if (spear->data < _new->data) {                        if (spear->right == 0) {                 spear->right = _new;
                return;
            }
            else {
                                spear = spear->right;
            }
        }
        else {                         if (spear->left == 0) {                 spear->left = _new;
                return;
            }
            else {
                                spear = spear->left;
            }
        }
    }
}


void traversal_preorder(struct node* _cur) {
    if (_cur == 0) {
        return;
    }

    printf("%d\n", _cur->data);
    traversal_preorder(_cur->left);
    traversal_preorder(_cur->right);
}

void traversal_inorder(struct node* _cur) {

    if (_cur == 0) {
        return;
    }

    traversal_inorder(_cur->left);
    printf("%d\n", _cur->data);
    traversal_inorder(_cur->right);

}


struct node* stack[STACK_SZ];
int top = -1;

int isFull(void) {
    return (top == (STACK_SZ - 1));
}

int isEmpty(void) {
    return (top == -1);
}

void push(struct node* _cur) {

    if (isFull()) {
        return;
    }

    top++;
    stack[top] = _cur;
    return;
}

struct node* pop(void) {

    if (isEmpty()) {
        return 0;      }

    struct node* result = stack[top];
    top--;
    return result;
}
void traversal_inorder_stack(struct node* _cur) {

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

int main(void) {

    addToBST(20);
    addToBST(10);
    addToBST(30);
    addToBST(40);
    addToBST(5);

    struct node* spear = root;

    ///traversal_inorder(spear);

    traversal_inorder_stack(root);

    return 0;
}

