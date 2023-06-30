#include <stdio.h>
#include <stdlib.h> 

struct node {
	int data;
	struct node* next;
};

struct node* head = 0;



void addToSLL(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = 0;

	if (head == 0) {
		head = _new;
		return;
	}

	struct node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}

	temp->next = _new;
	return;
}

void displaySLL(void) {
	struct node* temp = head;
	while (temp != 0) {
		if (temp->data == 0) {
			return;
		}
		printf("%d ", temp->data);
		temp = temp->next;
	}


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
	addToSLL(_v);
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
	
	if ((head->data == 0) &&( head->next == 0)) {
		printf("0");
	}
	else if (head->next == 0) {
		printf("%d", head->data);
	}
	else {
		int sum = 0;
		struct node* spear = head;
		while (spear->next != 0) {
			sum = sum + spear->data;
			spear = spear->next;
		}
		printf("%d", sum + spear->data);
	}
	return 0;
}