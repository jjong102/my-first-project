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

    if (head) { // head가 처음이 아니면
        node* temp = head; //head 복사해주고
        if (_v % 2) { // _v가 홀수일때
            if (head->data % 2 == 0) { // head의 데이터가 짝수이고
                _new->next = head; // 새로운 노드를 head전에 넣는다.
                head = _new; // 그리고 head를 새로운 노드로 옮긴다.
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