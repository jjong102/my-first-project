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


struct node* findSLL(int _v) {
	struct node* temp = head;

	while (temp != 0) {
		if (temp->data == _v) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
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

int delFromFront(void) {
	if (head == 0) {
		return -999;
	}

	struct node* spear = head;
	head = head->next;
	int res = spear->data;
	free(spear);
	return res;
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

void insertInto(int _findv, int _addv) {

	struct node* target = findSLL(_findv);
	if (target == 0) {
		return;
	}
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _addv;
	_new->next = 0;
	_new->next = target->next;
	target->next = _new;
	return;
}

void delFromSLL(int _v) {
	struct node* spear = findSLL(_v);

	if (spear == 0) {
		return;
	}

	if (head == spear) {
		head = head->next;
		free(spear);
		return;
	}

	struct node* prev = head;

	while (prev->next != spear) {
		prev = prev->next;
	}

	prev->next = spear->next;
	free(spear);
	return;
}


int main(void) {
	int temp;
	
	scanf_s("%d", &temp);
	addToFront(temp);
	while (temp != 0) {
		scanf_s("%d", &temp);
		// 1. 홀수가 들어오면 앞으로 보냄
		if (temp % 2 != 0) {
			//	1-1. 앞에 홀수가 아무것도 없을때
			//		1-1-1. 그냥 앞에다가 놓는다.
			if ((head->data) % 2 == 0) { // 앞에 수가 짝수
				addToFront(temp);
			}
			//	1-2. 앞에 홀수가 있을때
			else { // 앞에 수가 홀수이고 뒤에 수를 알 수 없을때
				// 1-2-1. 일단 홀수를 찾아 
				struct node* spear = head;
				while ((spear->next->data) % 2 != 0) {
					spear = spear->next;
				}
				// 1-2-2. 그 다음에 붙인다. 지금 spear->next에는 짝수가 들어가 있음.
				insertInto(spear->data, temp);
			}
			
			
		}
		else {
			addToSLL(temp);
		}
	}
	
	displaySLL();



}