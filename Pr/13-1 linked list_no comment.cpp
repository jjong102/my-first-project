#include <stdio.h>
#include <stdlib.h> 

struct node { // node struct를 만들어서 값을 품고 있는 data와 다음 node을 가리킬 next 포인터를 만들어 준다.
	int data;
	struct node* next;
};

struct node* head = 0; // node pointer를 head라는 이름으로 설정해준다. head는 0으로 만들어 준다.


// SLL에 새로운 노드를 만들어 바로 뒤에 추가해준다.

void addToSLL(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node)); 		
	_new->data = _v; // 데이터는 가져온 값으로 해주고
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

	printf("SLL안의 노드개수는: %d개 입니다.\n", countSLL());

	printf("20을 가진 노드의 주소 %x 입니다유!\n", findSLL(20));
	
	struct node* temp = findSLL(20);
	
	printf("%d\n", temp->data); 
	
	destroySLL();
	
	if (head != 0) {
		printf("제대로 destroy하지 못했음.\n");
	}

	return 0;
}
