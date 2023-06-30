#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node* next;
}node;
node* head = 0;

void find_SLL_cut (int _v) {
	node* temp = head;
	while (temp->next != 0) {
		
		if (head->data == _v) {
			head = head->next;
			free(temp);
			temp = head;
		}
		
		else if (temp->next->data == _v) {
			node* spear = temp->next;
			temp->next = temp->next->next;
			free(spear);
		}

		else {
			temp = temp->next;
		}
	}

	if (head->data == _v) {
		free(head);
		head = 0;
	}
	return;
}


void addToSLL (int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->next = 0;
	_new->data = _v;
	node* temp = head;
	if (head == 0) {
		head = _new;
		return;
	}
	while (temp->next != 0) {
		temp = temp->next;
	}
	temp->next = _new;
	return;
}



int main(void) {
	int v = 0;
	
	while (1) {
		scanf_s("%d", &v);
		if (v == 0) {
			break;
		}

		else if (v == -1) {
			node* temp = head;
			while (temp != 0) {
				printf("%d", temp->data);
				temp = temp->next;
			}

			if (head == temp) {
				printf("-999");
			}

			return 0;
		}
		addToSLL(v);
		
	}

	while (1) {
		scanf_s("%d", &v);
		if (v == -1) {
			node* temp = head;
			while (temp != 0) {
				printf("%d ", temp->data);
				temp = temp->next;
			}

			if (head == temp) {
				printf("-999");
			}

			return 0;
		}
		find_SLL_cut(v);
	}

	return 0;
}