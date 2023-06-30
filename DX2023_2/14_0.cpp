#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
	node* prev;

}node;

node* head = 0;

node* creatDLL(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->next = _new->prev = 0;
	return _new;
}

void addToDLL(int _v) {
	node* _new = creatDLL(_v);

	if (head == 0) {
		head = _new;
		return;
	}

	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}

	temp->next = _new;
	_new->prev = temp;
	return;
}

void reverseDisplayDLL(void) {
	node* temp = head;
	if (head == 0) {
		return;
	}

	while (temp->next != 0) {
		temp = temp->next;
	}

	while (temp != 0) {
		printf("%d\n", temp->data);
		temp = temp->prev;
	}

	return;
}

node* findDLL(int _t) {
	node* temp = head;

	while (temp != 0) {
		if (temp->data == _t) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

void insertIntoDLL(int _t, int _v) {
	node* _new = creatDLL(_v);
	node* temp = findDLL(_t);

	if (temp == 0) {
		return;
	}
	
	_new->prev = temp;
	_new->next = temp->next;
	temp->next = _new;
	if (_new->next != 0) {
		_new->next->prev = _new;
	}

	return;
}

void delFromDLL(int _v) {
	node* spear = findDLL(_v);
	if (spear == 0) {
		return;
	}
	
	else if (spear == head) {
		head = head->next;
		free(spear);
		if (head != 0) {
			head->prev = 0;
		}
		return;
	}

	spear->prev->next = spear->next;
	if (spear->next != 0) {
		spear->next->prev = spear->prev;
	}
	free(spear);
	return;
}



int main(void) {
	addToDLL(10);
	addToDLL(20);
	addToDLL(30);
	addToDLL(40);

	insertIntoDLL(20, 25);
	reverseDisplayDLL();
	return 0;
}