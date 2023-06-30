
#if 0
// Doubly Linked List
// ���� �ΰ�, next, prev
// head
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev; // DLL���� �߰��� �κ�
};

struct node* head = 0;

//node�� ����� �Լ�
struct node* createNode(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = _new->prev = 0;
    return _new;
}

void addToDLL(int _v) {

    struct node* _new = createNode(_v);

    //1. ����ִ� ���.
    if (head == 0) {
        head = _new;
        return;
    }

    // ���� ã�Ƽ� �߰�
    struct node* spear = head;
    while (spear->next != 0) {
        spear = spear->next;
    }

    // �̼���, spear�� ������ ��带 �� ��� ����.

    // �� ����
    spear->next = _new;
    _new->prev = spear;
    return;
}

void displayReverseDLL(void) {
    //�� �ڷ� ���� �ϳ��� ������ ����ϱ�
    if (head == 0) { //head�� 0�ΰ�� �� �̸� �������ֱ�
        return;
    }

    struct node* spear = head;
    while (spear->next != 0) { //spear�� �� ���� node�� ����Ű�� ����.
        spear = spear->next;
    }

    //�Ųٷ� ���鼭 �ϳ��� ���
    while (spear != 0) {
        printf("%d\n", spear->data);
        spear = spear->prev;
    }

    return;
}

struct node* findNode(int _t) {
    struct node* spear = head;

    while (spear != 0) {
        if (spear->data == _t) {
            return spear;
        }
        spear = spear->next;
    }
    return spear;
}

// _t: ã�ƾ� �� ���
// _v: �߰��ؾ� �� ���
void insertIntoDLL(int _t, int _v) {

    // _t�� ���� ��� ã��
    struct node* spear = findNode(_t);

    if (spear == 0) {
        return; // _t�� ���� ��尡 ����.
    }

    // ����, �߰�����.. spear �ڿ�...
    struct node* _new = createNode(_v); //�߰��� ��带 �����

    // �ƽ��� �ְ� ���� �����Ѵ�.
    _new->prev = spear;
    _new->next = spear->next; // null�� ��쵵 �������.
    spear->next = _new;

    // ���Ⱑ �߿�!
    // �� �ڿ� ���� �ִ� ��쿡��, 
    if (_new->next != 0) { //next�� NULL�� ��� �����߻�
        _new->next->prev = _new;
    }
    return;
}

void delFromDLL(int _t) {
    //t�� ���� ��带 ã�´�..
    struct node* spear = findNode(_t);
    if (spear == 0) {
        return; //thank you.
    }
    //�λ� ���̴� ���

    // 1. ���� spear== head, head����
    if (spear == head) {
        head = head->next;
        // ����
        free(spear);
        if (head != 0) {
            head->prev = 0;
        }
        return;
    }
    // 2. �߰� Ȥ�� ���� �ִ� ���
    spear->prev->next = spear->next; // ����... ���Ҹ��� �𸣰ڴ�..
    if (spear->next != 0) { //�� �ڿ� ���� ���� ����
        spear->next->prev = spear->prev;
    }
    free(spear); //����
    return;
}

int main(void) {

    addToDLL(10);
    addToDLL(20);
    addToDLL(30);


    displayReverseDLL();
    // 20�� ���� ��带 ã�Ƽ�, 90�� ���� ��带 �ڿ� �߰�
    insertIntoDLL(20, 90);

    delFromDLL(90); //90�� ���� ��带 ã�Ƽ� �����

    displayReverseDLL();

    return 0;
}


//done -- addToFront <---�� �տ� �߰�
//done -- delFromFront <--�� �� ���� �����ϰ�, �� ���� ��ȯ
//done -- delFromLast <-- �� �� ���� �����ϰ�,  �� ���� ��ȯ
//done-- insertInto <-- Ư�� ��带 ã�Ƽ�,  �� �ڿ� �߰�
// del FromDLL <-- Ư�� ��带 ã�Ƽ� ����
#endif
