//-------------------------------------------------
// Doubly Linked List
// ���� �ΰ�, nextm prev
// head
//-------------------------------------------------



#if 1
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev; // DLL���� �߰��� �κ�
};
struct node* head = 0;

// node�� ����� �Լ�
struct node* createNode(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = _new->prev = 0;
	return _new;
}

void addToDLL(int _v) {
	struct node* _new = createNode(_v);
	
	// ��� �ִ� ���
	if (head == 0) {
		head = _new;
		return;
	}

	// ���� ã�Ƽ� �߰�
	struct node* spear = head; 
	while (spear->next != 0) {
		spear = spear->next;
	}

	// �̼���, spear�� ������ ��带 ��� ����.
	// �ȿ���
	spear->next =_new;
	_new->prev = spear;
	return;
}

void displayDLL(void) {

	struct node* temp = head;

	while (1) { // (temp != 0)

		if (temp == 0) {
			break;
		}

		printf("%d\n", temp->data);
		temp = temp->next;
	}


}

void displayReverseDLL(void) {

	// epty list Ȯ��
	if (head == 0) {
		return;
	}

	struct node* spear = head;
	while (spear->next != 0) { // spear�� �� ���� ��带 ����Ű�� ����.
		spear = spear->next;
	}

	// �Ųٷ� ���鼭 �ϳ��� ���
	while (spear != 0) { 
		printf("%d\n", spear->data);
		spear = spear->prev;
	}

	return;
}

// _t�� ���� node�� ã�Ƽ�
// �ּ� ��ȯ
struct node* findNode(int _t) {

	struct node* spear = head;

	while (spear) {
		if (spear->data == _t) {
			break;
		}
		spear = spear->next;
	}
	return spear;

}
// _t : ã�ƾ� �� ���
// _v :�߰��ؾ� �� ���
void insertIntoDLL(int _t, int _v) {
	
	// _t�� ���� ��� ã��
	struct node* spear = findNode(_t);

	if (spear == 0) {
		return; // _t�� ���� ��尡 ����.
	}

	// ����, �߰� ����...spear�ڿ�
	struct node* _new = createNode(_v);

	// �ƽ��� �ְ� ���� �����Ѵ�.
	_new->prev = spear;
	_new->next = spear->next; // null�� ��쵵 �������.
	spear->next = _new;

	// ���Ⱑ �߿�!!
	//�� �ڿ� ���� �ִ� ��쿡��,
	if (_new->next != 0) {
		_new->next->prev = _new;
	}
	return;
}

// _t�� ���� ��带 ����
// 
void delFromDLL(int _t) {
	
	// _t�� ���� node�� ã�´�.
	struct node* spear = findNode(_t);
	if (spear == 0) { //thank you!
		return;
	}
	// �λ� ���̴� ���

	//1. ���� spear == head, head ����
	if (spear == head) {
		//head ����
		head = head->next;
		// ����
		free(spear);
		if (head != 0) {
			head->prev = 0; // �ܵ� node�� �ƴ� ���.
		}
		return;
	}

	//2. �߰� Ȥ�� ���� �ִ� ���
	spear->prev->next = spear->next;
	if (spear->next != 0) { // �� �ڿ� ���� ���� ����
		spear->next->prev = spear->prev;
	}
	free(spear); // ����
	return;
}





int main(void) {

	addToDLL(10);
	addToDLL(20);
	addToDLL(30);


	//displayReverseDLL();
	displayDLL(); //SLL�� ���� 

	// 20�� ���� ��带 ã�Ƽ� �� �ڿ� 90�� �߰� 
	insertIntoDLL(20, 90);

	//delFromDLL(90); // 90�� ���� ��带 ã�Ƽ� �����.
	displayDLL();
	//displayReverseDLL();
	


	return 0;
}
#endif