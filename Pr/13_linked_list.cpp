//--------------------------------------------
// p. 176, ���Ḯ��Ʈ == linked list
// 
// ������ ������ ��!!!!
// 
// array�� 4�� ����
//		1. ũ�Ⱑ ����,
//		2. ���ӵ� �޸� ������ �ʿ�
//		3. �߰��� �����ֱ�,, �ſ� �������!
//		4. �߰��� ����������, ���� ä��Ⱑ �����.
// 
// ���� 2. �׷��� linked list��� ���� ���Դ�.
//		array�� ��� ������ �غ�!!!
//		array�� ��� ������ �Ҿ���...
// 
//		����1 : �ʿ��� ��ŭ�� �޸� ���
//		����2 : ���ӵ��� ���� �޸𸮵�, ����� ����.
//		����3,4: �����ְ�, ����������, ---> Ƽ�� �ȳ�!! �ſ� ȿ�������� ó��
// 
//		����1 : �ſ� ����
//		����2 : ������ ����
// 
//		�� �ڿ��� �� ģ�� --> linked �Ǿ� �ֵ�!! ��--> ��--> ��-> ��
// 
// Linked list�� ������ ����.
//	Node���� ���� (��-->)
//  linked list�� ������ҵ��� node��� �θ���.
//	�� node�� �����͸� �����ϴ� ������,
//		�� ���� ���� ����Ű�� ��ũ�� ����
//--------------------------------------------
#if 1
#include <stdio.h>
#include <stdlib.h> // malloc ������ �ʿ�

// linked list�� �⺻ ����� node
// linked list : LL
// Singly Linked list : SLL 

struct node {
	int data;
	struct node* next;
};

struct node* head = 0; // head�� linked list�� ó���� �˷��ش���!

// stack���� top, queue���� front/rear, linked list���� head

// _v �������� SLL�� ���� �߰��Ѵ�.
// ���� �þ�� ����Ʈ�� ����


void addToSLL(int _v) {
	// _v ���� ������ node�� �޸𸮿� �����Ѵ�.
	// data type�� casting�ϴ� ����
	// malloc�� ��ȯ���� void* (�ּҸ� ��ȯ�� �ش�.)
	// type�� �����Ƿ� (void), ������ type���� casting
	// _new�� ���� �Ҵ���� node ����ü�� �ּҸ� ����Ű�� �ִ�.
	
	// ����!! _new�� �Ҿ������, �Ҵ���� ������ �ٽ� ã�ư� ����� ����.

	struct node* _new = (struct node*)malloc(sizeof(struct node)); //���ο� ��带 �����.
	// -> ȭ��ǥ�� ����ϴ� ���� : _new�� ������ �̱� ������
	_new-> data = _v;

	_new-> next = 0; //�ű� ���� �ڿ� ���� ��尡 �����Ƿ�, 0(null)�� �ʱ�ȭ
	
	//_new�� ���� SLL�� �߰�

	// ����� �� 2����
	// 1. �� SLL�� ���

	if (head == 0) {
		head = _new;
		return;
	}
	// 2. �ƴ� ���
	
	// 2.1 ���� SLL���� �� ���� ����� �ּҸ� �˾Ƴ���.
	struct node* temp = head; // head�� ������ �����̸� �ٽô� �ڷ� ���ư� �� ����... ���� ���ο� ������ ����
	while (temp -> next != 0) {
		temp = temp->next;
	}

	// 2.2 �ǳ� ����� next�� ���ο� ����� �ּҸ� ����ִ´�.
	temp->next = _new; // ���ο� ����� �ּҸ� �������ش�. 
	return;
	// h -> �� -> �� -> ��
}

void displaySLL(void) {
	struct node* temp = head;
	while (1) { // (temp != 0)
		
		if (temp == 0) {
			break;
		}

		printf("%d\n", temp->data);
		temp = temp->next;
	}


}

// SLL�� ���Ե� node������ ��ȯ
int countSLL(void) {
	struct node* temp = head;
	int cnt = 0; // ��� ����

	while (temp != 0) {
		cnt++;
		temp = temp->next;
	}
	return cnt++;
}

// _v���� ������ ��带 ã�Ƽ�,
// �� ����� �ּҸ� ��ȯ
// �׷���, ��ȯ���� struct node*
// ��ȯ��
//	- _v�� ���� ����� �ּ�
//	- 0 : �׷� ��尡 ���� ��
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
		head = head->next; // head�� ������½ ������ �ѱ��.
		free(spear);
		spear = head;
	}
	return;
}

// _v�� ���� ��带 �� �տ� �߰�
void addToFront(int _v) {
	// ���ο� node�� 1�� �Ҵ� �޾Ƽ�, _v�� ����, �� ��带 _new�� ����Ų��.
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = 0;

	// ����� ��. 1 SLL == empty
	if (head == 0) {
		head = _new;
		return;
	}

	// ����� ��. 2, SLL�� ���� ������. (������ ����� �߿��ϴ�!)
	_new->next = head; // SLL�� ���Ģ = ���ο� ����� �ƽ���. ������ (�ռ� �߿�!!!)
	head = _new;
	return;
}

int delFromFront(void) {

	if (head == 0) {
		return -999; // SLL�� �ֺ���ٴ� �ǹ�.
	}

	struct node* spear = head;
	//head ����
	head = head->next;
	//������ ����
	int res = spear->data;
	//����
	free(spear);
	//���尪 ��ȯ
	return res;

}

int delFromLast(void) {

	// thank you.1
	if (head == 0) {
		return -999;
	}

	if (head->next == 0) {
		int res = head->data;
		free(head);
		head = 0;
		return res;
	}

	// oh my god .3
	// 1. �� �ڿ��� �� ��° ��忡 â�� �Ŵ´�.
	struct node* spear = head;

	while (spear->next->next != 0) {
		spear = spear->next;
	}
	int res = spear->next->data; //������ ����
	//����
	free(spear->next);
	//���� ó��
	spear->next = 0;
	return res;
}

// _findv���� ���� ��带 ã�Ƽ�,
// �� ���� _addv�� ���� ���ο� ��带 �߰��Ѵ�.
void insertInto(int _findv, int _addv) {

	// _findv�� ���� ��尡 ���ٸ�,
	struct node* target = findSLL(_findv);
	if (target == 0) { // _findv�� ���� ��尡 ����. thank youououoyuyuyu
		return;
	}
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _addv;
	_new->next = 0;

	// �ٿ��ֱ�
	// �ƽ���.
	_new->next = target->next;
	target->next = _new;
	return;
}
// _v���� ���� ��带 ã�Ƽ� ����
void delFromSLL(int _v) { 
	//_v���� ���� ��带 ã�´�.
	struct node* spear = findSLL(_v);

	if (spear == 0) { // ��ã����, thank you
		return;
	}
	
	// �����ؾ��� ���̽�
	// ������ �ϴ� ���� head�� ���
	if (head == spear) {
		// head ����
		head = head->next;
		// ����
		free(spear);
		return;
	}

	// ������ ���̽�
	// spear ���� ��尡 �߰��� �ִ� ���. �ּ��� ��尡 2���� �ִ� ���

	struct node* prev = head;
	//prev�� â���� ����� ���� ��尡 �� �� ���� �̵�.
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
	
	// insertInto <--- Ư�� ��带 ã�Ƽ�, �� �ڿ� �߰�
	insertInto(20, 99);
	
	// delFromSLL <--- Ư�� ��带 ã�Ƽ� ����
	delFromSLL(99);
	

	// SLL�� �տ������� �ڷ� �������鼭
	// ����忡 ����� ������ ����Ѵ�.
	displaySLL();

	// countSLL <--- SLL �ȿ� �ִ� ��� ������ ��ȯ
	printf("SLL���� ��尳����: %d�� �Դϴ�.\n", countSLL());
	
	// findSLL <--- SLL �ȿ� �ִ� Ư�� ��� ��ġ�� �˻�
	printf("20�� ���� ����� �ּ� %x �Դϴ���!\n", findSLL(20));
	struct node* temp = findSLL(20);
	printf("%d\n", temp->data); // ----> must be 20, �� ���� ��ȯ

	// destroySLL <--- SLL ��带 ��� ����
	destroySLL();
	if (head != 0) {
		printf("����� destroy���� ������.\n");
	}
	
	// addToFront <--- �� �տ� �߰�
	// displaySLL(); �տ� �־��

	// delFromFont <--- �� �� ���� ����, �� ���� ��ȯ
	// displaySLL(); �տ� �־��

	
	// displaySLL(); �տ� �־��

	
	
	
	
	
	
	
	


	return 0;
}
#endif