#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	node* next;
}node;

node* head = 0;

void addToSLL(int _v) {
	node* _new = (node*)malloc(sizeof (node));

	_new->data = _v;
	_new->next = 0;

	if (head == 0) {
		head = _new;
		return;
	}
	node* spear = head;
	while (1) {
		if (spear->next == 0){
			break;
		}
		spear = spear->next;
	}
	spear->next = _new; // spear ������ �ֿ� �����
	return;
}


node* findSLL(int _v) {
	node* spear = head;
	while (spear != 0) { //���࿡ ��ã���� ������ �����ؾ���
		if (spear->data == _v) {
			return spear;
		}
		spear = spear->next;
	}
	return spear; //  ��ã���� 0 ���������
}

void insertToSLL(int _findv, int _addv) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _addv;
	_new->next = 0;

	node* temp = findSLL(_findv);
	if (temp == 0) {
		return; // ��ã�� ���� �����ؾ���
	}

	
	_new->next = temp->next;
	temp->next = _new;
	return;
}

void delFromSLL(int _v) {
	node* spear = findSLL(_v);

	if (spear == 0) {
		return; //  �� ã���� �׸��ؾ���
	}


	if (head == spear) {
		head = spear->next;
		free(head);
		return;
	}

	node* temp = head;
	while (1) {
		if (temp->next == spear) {
			break;
		}
		temp = temp -> next;
	}

	temp->next = spear->next;
	free(spear);
	return;
}

int delFromfront(void) {
	if (head == 0) {
		return -999;
	}

	node* spear = head;
	head = head->next;
	int res = spear->data;
	free(head);
	return res;
}


void addToFront(int  _v) {

	
	node* _new = (node*)malloc(sizeof(node));
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

int countSLL(void) {
	int cnt = 0;
	node* spear = head;
	while (1) {
		if (spear->next == 0) {
			break;
		}
		spear = spear->next;
		cnt++;
	}
	return cnt + 1;
}

void destroySLL(void) {
	
	while (1) {
		node* spear = head;
		if (spear->next == 0) {
			free(head);
			head = 0;
			return;
		}
		head = head->next;
		free(spear);
	}
}

int delFromFront(void) {
	if (head == 0) {
		return -999;
	}

	node* temp = head;
	int res = head->data;
	head = head->next;
	free(temp);
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

	node* spear = head;
	while (1) {
		if (spear->next->next == 0) {
			break;
		}
		spear = spear->next;
	}
	int res = spear->next->data;
	free(spear->next);
	spear->next = 0;
	return res;
}

void displaySLL(void) {
	node* temp = head;
	while (temp != 0) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
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
	
	insertToSLL(20, 99);
	
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