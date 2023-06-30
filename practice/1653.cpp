#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define SZ 11

typedef struct node {
    char data[SZ];
    struct node* left;
    struct node* right;
} node;

node* root = 0;

int which_is_bigger(char* a, char* b) {
    for (int i = 0; i < SZ; i++) {
        if (a[i] == '\0' || b[i] == '\0') {
            return (a[i] - b[i]);
        }
        if (a[i] != b[i]) {
            return (a[i] - b[i]);
        }
    }
    return 0;
}

void addToBST(char* _v) {
    node* _new = (node*)malloc(sizeof(node));
    strncpy(_new->data, _v, sizeof(_new->data) - 1);
    _new->data[sizeof(_new->data) - 1] = '\0';
    _new->left = _new->right = 0;

    if (root == 0) {
        root = _new;
        return;
    }
    node* temp = root;
    while (1) {
        if (strcmp (temp->right, temp->left) > 0) {
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

int main(void) {
    char s[SZ];

    while (1) {
        scanf("%s", s);

        if (strcmp(s, "end") == 0) {
            break;
        }
        addToBST(s);
    }

    int v = 0;
    node* temp = root;
    while (1) {
        if (temp == 0) {
            printf("INVALID");
            return 0;
        }

        scanf("%d", &v);
        if (v == 0) {
            temp = temp->left;
        }
        else if (v == 1) {
            temp = temp->right;
        }
        if (v == -1) {
            printf("%s ", temp->data);
            return 0;
        }
    }
    return 0;
}