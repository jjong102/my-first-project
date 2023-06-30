#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
    int data;
    struct _NODE* next;
} node;
node* head = 0;

void addToSLL(int _v) {
    node* _new = (node*)malloc(sizeof(node));
    _new->data = _v;
    _new->next = 0;

    if (head) { // head�� ó���� �ƴϸ�
        node* temp = head; //head �������ְ�
        if (_v % 2) { // _v�� Ȧ���϶�
            if (head->data % 2 == 0) { // head�� �����Ͱ� ¦���̰�
                _new->next = head; // ���ο� ��带 head���� �ִ´�.
                head = _new; // �׸��� head�� ���ο� ���� �ű��.
                return;
            }
            while (temp->next) {
                if (temp->next->data % 2 == 0) {
                    _new->next = temp->next;
                    temp->next = _new;
                    return;
                }
                temp = temp->next;
            }
            temp->next = _new;
            return;
        }
        else {
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = _new;
            return;
        }
    }
    else {
        head = _new;
    }
    return;
}
void displayAndDestroySLL() {
    node* temp;
    while (head) {
        printf("%d ", head->data);
        temp = head->next;
        free(head);
        head = temp;
    }
    return;
}
int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        addToSLL(n);
        scanf("%d", &n);
    }
    displayAndDestroySLL();
    return 0;
}