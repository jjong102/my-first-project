#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
}node;

node* head = 0;

void addToSLL(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->next = 0;

	
	if (head == 0) {
		head = _new;
		return;
	}
	
	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	temp->next = _new;
	return;
}

void displaySLL(void) {
	
	node* temp = head;
	while (temp != 0) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return;
}

int countSLL(void) {
	node* temp = head;
	int cnt = 0;
	while (temp != 0) {
		cnt++;
		temp = temp->next;
	}
	return cnt++; //while문을 돌면서 마지막 하나를 카운트 못함.
}
node* findSLL(int _v) {
	node* temp = head;
	while (temp != 0) {
		if (temp->data == _v) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

int delFromFront(void) {
	if (head == 0) {
		return -999;
	}

	node* spear = head;
	head = head->next;
	int res = spear->data;
	free(spear);
	return res;
}

int delFromLast(void) {
	if (head == 0) {
		return -999;
	}

	else if (head->next = 0) {
		int res = head->data;
		free(head);
		head = 0; //마지막 0으로 만들어줘야 할 수 있어!
		return res;
	}

	node* spear = head;
	while (spear->next->next != 0) {
		spear = spear->next;
	}
	int res = spear->next->data;
	free(spear->next);
	spear->next = 0;
	return res;
}

void distroySLL(void) {
	node* spear = head;

	while (head != 0) {
		head = head->next;
		free(spear);
		spear = head;
	}
	return;
}

void addToFront(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->next = 0;
	
	if (head == 0) {
		head = _new;
		return;
	}
	
	_new->next = head;
	head = _new;
	return;
}


void insertInto(int _findv, int _addv) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _addv;
	_new->next = 0;

	node* target = findSLL(_findv);
	if (target == 0) {
		return;
	}

	_new->next = target->next;
	target->next = _new;
	return;
}

void delFromSLL(int _v) {
	node* spear = findSLL(_v);
	if (spear == 0) {
		return;
	}
	if (head == spear) { // 이 경우 생각하세요!
		head = head->next;
		free(spear);
		return;
	}
	node* temp = head;
	while (temp->next != spear) {
		temp = temp->next;
	}

	temp->next = spear->next;
	free(spear);
	return;
}



int main(void) {
	addToSLL(10);
	addToSLL(20);
	addToSLL(30);
	addToSLL(40);
	addToFront(5);
	insertInto(20, 25);
	/*delFromFront();
	delFromLast();*/
	delFromSLL(20);
	displaySLL();

	//printf("%d\n", findSLL(10)->data);
	
	return 0;
}