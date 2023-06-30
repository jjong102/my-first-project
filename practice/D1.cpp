#include <stdio.h>
#include <stdlib.h>

// DLL

typedef struct node {
	int data;
	node* next;
	node* prev;
}node;

node* head = 0;

void addToDLL(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->next = _new->prev = 0;

	if (head == 0) {
		head = _new;
		return;
	}

	node* temp = head;
	while (temp ->next != 0) {
		temp = temp->next;
	}
	_new->prev = temp;
	temp->next = _new;
	return;
}
node* findDLL(int _v) {
	node* spear = head;
	while (spear != 0) {
		if (spear->data == _v) {
			return spear;
		}
		spear = spear->next;
	}
	return spear;
}

int delFromDLL(int _v) {
	node* spear = findDLL(_v);
	
	if (spear == 0) {
		return 0;
	}
	if (spear == head) {
		head = head->next;
		free(spear);
		if (head != 0) {
			head->prev = 0;
		}
		return 1;
	}

	spear->prev->next = spear->next;
	if (spear->next != 0) {
		spear->next->prev = spear->prev;
	}
	return 1;
}



int main(void) {
	int v = 0;

	while (1) {
		scanf_s("%d", &v);
		if (v == 0) {
			break;
		}
		if (v == -1) {
			node* temp = head;
			if (head == 0) {
				printf("-999");
				break;
			}
			while (temp->next != 0) {
				temp = temp->next;
			}
			while (temp != 0) {
				printf("%d ", temp->data);
				temp = temp->prev;
			}

			return 0;
		}
		addToDLL(v);
	}

	while (1) {
		scanf_s("%d", &v);
		if (v == -1) {
			node* temp = head;
			if (head == 0) {
				printf("-999");
				break;
			}
			while (temp->next != 0) {
				temp = temp->next;
			}
			while (temp != 0) {
				printf("%d ", temp->data);
				temp = temp->prev;
			}
			
			break;
		}
		while (delFromDLL(v)) {
			delFromDLL(v);
		}
		
	}


	
	return 0;
}