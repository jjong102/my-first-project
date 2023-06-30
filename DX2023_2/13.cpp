#include <stdio.h>
#include <stdlib.h>


typedef struct node{
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

	return cnt++;

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

// 앞의 값을 지우고 그 값을 반환해 주는 것..
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

	else if (head->next == 0) {
		int res = head->data;
		free(head);
		head = 0; // 0으로 초기화 해준다.
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

void insertInto(int _findv, int _addv) {
	
	node* target = findSLL(_findv);
	if (target == 0) {
		return;
	}
	
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _addv;
	_new->next = 0;
	
	_new->next = target->next;
	target->next = _new;
	return;
}

void insertInto_nonefindSLL(int _findv, int _addv) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _addv;
	_new->next = 0;

	node* temp = head;
	while (temp != 0) {
		if (temp->data == _findv) {
			_new->next = temp->next;
			temp->next = _new;
			return;
		}
		temp = temp->next;
	}
	return;
}

void dellFromSLL(int _v) {
	node* spear = findSLL(_v);
	
	if (spear == 0) {
		return;
	}

	// node가 한개 있을때
	else if (spear == head) {
		head = head->next;
		free(spear);
		return;
	}

	node* prev = head;
	while (prev->next != spear) {
		prev = prev->next;
	}
	prev->next = spear->next;
	free(spear);
	return;

}

int main(void) {
	
	addToSLL(10);
	addToSLL(20);
	addToSLL(30);
	addToSLL(40);

	// insertInto(20, 25);
	insertInto_nonefindSLL(20, 25);
	displaySLL();
	dellFromSLL(25);
	displaySLL();
	return 0;
}