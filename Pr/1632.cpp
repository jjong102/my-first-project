#include <stdio.h>
#include <stdlib.h> 

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node* head = 0;

struct node* createNode(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = _new->prev = 0;
	return _new;
}

void addToDLL(int _v) {
	struct node* _new = createNode(_v);

	if (head == 0) {
		head = _new;
		return;
	}

	struct node* spear = head;
	while (spear->next != 0) {
		spear = spear->next;
	}

	spear->next = _new;
	_new->prev = spear;
	return;
}

void displayDLL(void) {
	struct node* temp = head;
	while (temp != 0) {
		if (temp->data == 0) {
			return;
		}
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void displayReverseDLL(void) {

	if (head == 0) {
		return;
	}

	struct node* spear = head;
	while (spear->next != 0) {
		spear = spear->next;
	}

	while (spear != 0) {
		if (spear->data != 0) {
			printf("%d ", spear->data);
		}
		spear = spear->prev;
	}

	return;
}

int delFromLast(void) {
	if (head == 0) {
		return -999;
	}

	if (head->next == 0) {
		int res = head->data;
		free(head);
		head = 0;
		return res;
	}

	struct node* spear = head;

	while (spear->next->next != 0) {
		spear = spear->next;
	}

	int res = spear->next->data;
	free(spear->next);
	spear->next = 0;
	return res;
}


int isEmpty() {
	return ((head->data == 0) && (head->next == 0));
}

void push(int _v) {
	addToDLL(_v);
	return;
}
int pop() {
	return delFromLast();
}


int main() {
	int temp;
	scanf_s("%d", &temp);
	while (temp != 0) {
		if (temp == -1) {
			pop();
		}
		else {
			push(temp);
		}
		scanf_s("%d", &temp);
	}

	if ((head->data == 0) && (head->next == 0)) { //isEmpty
		printf("-999");
	}

	displayReverseDLL();
	displayDLL();

	return 0;
}