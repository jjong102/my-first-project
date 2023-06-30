#include <stdio.h>
#include <stdlib.h> 

struct node { // node struct�� ���� ���� ǰ�� �ִ� data�� ���� node�� ����ų next �����͸� ����� �ش�.
	int data;
	struct node* next;
};

struct node* head = 0; // node pointer�� head��� �̸����� �������ش�. head�� 0���� ����� �ش�.


// SLL�� ���ο� ��带 ����� �ٷ� �ڿ� �߰����ش�.

void addToSLL(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node)); 		
	_new->data = _v; // �����ʹ� ������ ������ ���ְ�
	_new->next = 0;  // 
	
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
	
	while (1) { 
		if (temp == 0) {
			break;
		}
		printf("%d\n", temp->data);
		temp = temp->next;
	}


}

int countSLL(void) {
	struct node* temp = head;
	int cnt = 0; 
	
	while (temp != 0) {
		cnt++;
		temp = temp->next;
	}
	return cnt++;
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

	addToSLL(10);
	addToSLL(20);
	addToSLL(30);
	addToSLL(40);

	addToFront(90);
	addToFront(80);

	delFromFront();
	delFromFront();

	delFromLast();

	insertInto(20, 99);

	delFromSLL(99);

	displaySLL();

	printf("SLL���� ��尳����: %d�� �Դϴ�.\n", countSLL());

	printf("20�� ���� ����� �ּ� %x �Դϴ���!\n", findSLL(20));
	
	struct node* temp = findSLL(20);
	
	printf("%d\n", temp->data); 
	
	destroySLL();
	
	if (head != 0) {
		printf("����� destroy���� ������.\n");
	}

	return 0;
}
