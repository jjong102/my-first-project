// ������ �ڵ�
// �󵵼��� ������ 
// ���� ���� �ΰ� ���ϰ�, �׷����� ��, �� ���ϰ�,, ������ Ʈ�� �ϼ�,,
// ���ս� ����

// ������ �ڵ� ���α׷�
// �켱����ť MINheap���

#include <stdio.h>
#include <stdlib.h>

#define Q_SZ 100

struct node {
	char c; //������ �ڵ带 �Ҵ���� ����.
	int freq;
	struct node* left;
	struct node* right;
};

// min heap == �켱����ť, �󵵼��� �������� �켱������ ����.
struct node* PQUE[Q_SZ + 1];
int idx = 0;

// huffman code�� ����� �������� �迭
char code[30] = { 0, }; // �ʱ⿡�� null character�� �ʱ�ȭ
int code_idx = -1; // �ڵ带 �߰��ؾ� �ϴ� ��ġ, 011

struct node* createNode(char _c, int _freq) {
	struct node* _new_node = (struct node*)malloc(sizeof(struct node));
	_new_node->c = _c;
	_new_node->freq = _freq;
	_new_node->left = 0;
	_new_node->right = 0;
	return _new_node;
}

void enqueue(struct node*_new_node) {
	// queue full
	if (idx == Q_SZ) {
		return;
	}

	idx += 1;
	PQUE[idx] = _new_node; // ����� �ּҸ� �ִ´�.

	//�θ� �ڱ⺸�� ũ��, ���� ���� �ö󰣴�. �ֳĸ� min heap
	int _cur_idx = idx;
		int _p_idx = _cur_idx / 2;

		while (_cur_idx > 1) {
			if (PQUE[_cur_idx]->freq < PQUE[_p_idx]->freq) {
				struct node* temp = PQUE[_cur_idx];
				PQUE[_cur_idx] = PQUE[_p_idx];
				PQUE[_p_idx] = temp;
				_cur_idx = _p_idx;
				_p_idx = _cur_idx / 2;
			}
			else {
				break;
			}
		}
}

struct node* dequeue(void) {

	// queue empty
	if (idx == 0) {
		return 0;
	}

	struct node* _res = PQUE[1]; //  ������
	// �����ָ� ����ؼ�, ������ �ְ� �ö�´�.
	// minheap ���� (complete binary tree ���� ������ ���ؼ�)
	PQUE[1] = PQUE[idx];
	idx--;

	int _cur_idx = 1;
	int  _child_idx = _cur_idx * 2; // �ϴ� �����ڽ�

	while (1) {
		if (_child_idx > idx) { // ���ڽ�
			break;
		}

		// 1. �ϴ� ������ �ڽ��� �־�� �ϰ�,
		// 2. ��, ��: �� �� �� �����ֿ͸� ���ϸ� �ȴ�.
		if ((_child_idx + 1 <= idx) && (PQUE[_child_idx]->freq > PQUE[_child_idx + 1]->freq)) {
			_child_idx += 1; // �������� ���� ���̴� ������ ������.
		}
		// ����, ������ ��, �θ�� �ڽİ��� ����
		if (PQUE[_cur_idx]->freq > PQUE[_child_idx]->freq) {
			// �ڽĿ��� �ڸ��� �����ְ� �����;� ��.
			struct node* temp = PQUE[_cur_idx];
			PQUE[_cur_idx] = PQUE[_child_idx];
			PQUE[_child_idx] = temp;
			_cur_idx = _child_idx;
			_child_idx = 2 * _cur_idx;
		}
		else {
			break;
		}
	}
	return _res;

	//minheap ���� (�θ�� �ڽĺ��� �۾ƾ� �Ѵ�.)
}
// minheap�� ��� ��� �������� �̿��ؼ�
// huffman tree�� �����,
// �������� rootnode�� ��ȯ�Ѵ�.
struct node* bulidHuffmanTree(void) {

	while (1) {
		// 1. 2���� ������.
		// ��, �Ѱ��� ������, ��ȯ�ϰ� ��.
		struct node* _first = dequeue();
		struct node* _second = dequeue();

		if (_second == 0) {
			return _first;
		}
		// 2. ����Ʈ���� ����, �ٽ� engueue
		struct node* _combined = createNode(0, _first->freq + _second->freq);
		_combined->left = _first;
		_combined->right = _second;

		enqueue(_combined);
	}
}

void genHuffmanCode(struct node* _node) {

	if (_node == 0) {
		return;
	}
	code_idx++;
	code[code_idx] = '0';
	genHuffmanCode(_node->left);
	code[code_idx] = 0; //���� ���� ���� �����.
	code_idx--;

	if (_node->c != 0) { // 'a' , 'b' ,,, �̷� �͵��� �ִٸ�,
		printf("%c ---> %s\n", _node->c, code);
	}
	
	code_idx++;
	code[code_idx] = '1';
	genHuffmanCode(_node->right);
	code[code_idx] = 0; //���� ���� ���� �����.
	code_idx--;
}
int main(void) {
	enqueue(createNode('c', 6));
	enqueue(createNode('a', 3));
	enqueue(createNode('z', 100));
	enqueue(createNode('b', 4));

	/*for (int i = 1; i <= idx; i++) {
		printf("%c   %d \n", PQUE[i]->c, PQUE[i]->freq);
	}*/
	/*while (1) {
		struct node* temp = dequeue();
		printf("%c ---> %d \n", temp->c, temp->freq);
	}*/

	struct node* temp = bulidHuffmanTree();
	// printf("%d\n", temp->freq); // 113 a, 3, b, 4, c,6 z100 ===> 113
	genHuffmanCode(temp);
	return 0;
}