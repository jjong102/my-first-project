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


int isEmpty(void) {
	return ((head->next == 0) && (head->prev == 0) && (head->data == 0)); 
}

void enqueue(int _v) {
	addToDLL(_v);
	return;
}

int dequeue(void) {
	if (isEmpty()) {
		return -999;
	}
	return delFromFront();
}

void displayDLL(void) {

	struct node* temp = head;

	while (1) {
		if (temp->next->data == 0) {
			break;
		}
		temp = temp->next;
	}

	// 최소 값이랑 최대 값이랑 다를때
	if (head->data != temp->data) {
		// 가장 큰 값이랑 가장 작은 값 제거
		delFromFront();
		delFromLast();
		delFromLast(); // 0 제거

		// 출력
		struct node* temp_2 = head;
		while (temp_2 != 0) {
			printf("%d ", temp_2->data);
			temp_2 = temp_2->next;
		}
		return;
	}

	// 최소 값이랑 최대 값이랑 같을때
	else {
		// -999
		printf("-999");
		return;
	}
}



int main(void) {
	int temp;
	scanf_s("%d", &temp);
	addToDLL(temp);
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
	
	// 일단 오름차순 정렬
	else {
		struct node* spear = head;
		while (spear->next != 0) {
			struct node* spear_2 = spear->next;
			while (spear_2->next != 0) {
				if (spear_2->data < spear->data) {
					int temp = spear->data;
					spear->data = spear_2->data;
					spear_2->data = temp;
					break;
				}
				else {
					spear_2 = spear_2->next;
				}
			}
			spear = spear->next;
		}

		displayDLL();


	}
		
	return 0;
}