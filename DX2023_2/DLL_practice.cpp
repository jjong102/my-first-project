#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	node* prev;
	node* next;
}node;

node* head = 0;

node* createNode(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->prev = _new->next = 0;
	return _new;
}

void addToDLL(int _v) {
	node* _new = createNode(_v);
	if (head == 0) {
		head = _new;
		return;
	}

	node* temp = head;
	while (1) {
		if (temp->next == 0) {
			break;
		}
		temp = temp->next;
	}

	_new->prev = temp;
	temp->next = _new;
	return;
}

node* findNode(int _v) {
	node* temp = head;
	while (1) {
		if (temp == 0) {
			break;
		}
		if (temp->data == _v) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

void InsertIntoDLL(int _fv, int _av) {
	node* spear = findNode(_fv);
	node* _new = createNode(_av);
	if (spear == 0) {
		return;
	}

	if (spear->next == 0) {
		_new->prev = spear;
		spear->next  = _new;
		return;

	}

	_new->prev = spear;
	_new->next = spear->next;
	spear->next = _new;
	_new->next->prev = _new;
	return;
}

void delFromDLL(int _v) {
	node* spear = findNode(_v);
	if (spear == 0) {
		return;
	}
	if (spear == head) {
		head = head->next;
		free(spear);
		if (head != 0) {
			head->prev = 0;
		}
		return;
	}

	if (spear->next == 0) {
		spear->prev->next = 0;
		free(spear);
		return;

	}

	spear->prev->next = spear->next;
	spear->next->prev = spear->prev;
	free(spear);
	return;



}
void displayreverse(void) {
	node* temp = head;
	while (1) {
		if (temp->next == 0) {
			break;
		}
		temp = temp->next;
	}

	while (1) {
		if (temp == head) {
			printf("%d \n", temp->data);
			break;
		}
		printf("%d \n", temp->data);
		temp = temp->prev;	
	}
	return;
}


int main(void) {
	addToDLL(10);
	addToDLL(20);
	addToDLL(30);
	addToDLL(40);
	
	InsertIntoDLL(20, 25);
	InsertIntoDLL(5, 25);
	InsertIntoDLL(10, 15);
	

	
	delFromDLL(15);
	delFromDLL(10);

	displayreverse();


	return 0;
}