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
	return ((head->next == 0) && (head->data == '0')); //뭔가 이상한데....
}
void destroySLL(void) {
	struct node* spear = head;

	while (head != 0) {
		head = head->next;
		free(spear);
		spear = head;
	}
	return;
}
int dequeue() {	
	if (isEmpty()) {
		return -999; 	
	}	
	else {
		return delFromLast();
	}
}

void enqueue(int _v) {
	addToSLL(_v);
	return;
}

int main(void) {
	int temp;
	scanf_s("%d", &temp);
	addToSLL(temp);
	while (temp != 0) {
		scanf_s("%d", &temp);
		if (temp == -1) {
			dequeue();
		}
		else {
			enqueue(temp);
		}

	}
	
	if (isEmpty()) {
		printf("0");
	}
	else {
		struct node* spear = head;
		int max = 0;
		while (spear->next != 0) {
			if (spear->data > spear->next->data) {
				max = spear->data;
			}
			spear = spear->next;
		}
		printf("%d", max);
	}

	
	
	
	
	return 0;
}