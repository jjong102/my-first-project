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

void addToFront(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
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
void insertIntoDLL(int _t, int _v) {

		struct node* spear = findNode(_t);

	if (spear == 0) {
		return; 	
	}
	struct node* _new = createNode(_v);

	_new->prev = spear;
	_new->next = spear->next; 	
	spear->next = _new;

	if (_new->next != 0) {
		_new->next->prev = _new;
	}
	return;
}

void delFromDLL(int _t) {

	struct node* spear = findNode(_t);
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

	spear->prev->next = spear->next;
	if (spear->next != 0) { 		
		spear->next->prev = spear->prev;
	}
	free(spear);
	return;
}


int main(void) {
	int temp;

	scanf_s("%d", &temp);
	addToFront(temp);
	while (temp != 0) {
		scanf_s("%d", &temp);
		if (temp % 2 != 0) {
			if ((head->data) % 2 == 0) {
				addToFront(temp);
			}
		
			else {
				struct node* spear = head;
				while ((spear->next->data) % 2 != 0) {
					spear = spear->next;
				}
				insertIntoDLL(spear->data, temp);
			}
		}

		else {
			addToDLL(temp);
		}
	}

	displayReverseDLL();
	
	return 0;
}