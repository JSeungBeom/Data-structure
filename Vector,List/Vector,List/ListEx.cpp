#include <iostream>

using namespace std;

struct node {
	int data; // ������ �ʵ�
	node* prev; // ���� ��带 ����Ű�� ��ũ �ʵ�
	node* next; // ���� ��带 ����Ű�� ��ũ �ʵ�
};

class nodeList {
private:
	node* header; // �� ���� ���
	node* trailer; // �� ���� ���
	int n; // list�� ������
public:
	// ������, ��� ���� �ʱ�ȭ
	nodeList() {
		header = new node();
		trailer = new node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL; // header�� trailer�� ���θ� ����Ű�� ����
		n = 0;
	};

	// list�� ������� �Ǵ��ϴ� �Լ�
	bool empty() {
		return (n == 0);
	};

	// list�� ũ�⸦ ����
	int size() {
		return n;
	}

	// list�� header�� next �ּҸ� ��ȯ
	node* begin() {
		return header->next;
	}

	// list�� trailer�� �ּ� ��ȯ
	node* end() {
		return trailer;
	}

	// pos�� �����f�� ��� ���ʿ� data�� �����ϴ� �Լ�
	void insert(node* pos, int data) {
		node* newNode = new node; // ���ο� ���
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos;
		// newNode�� ���� ����Ʈ�� �Ŵ޸� ����
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertFront(int data) {
		insert(begin(), data);
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	void erase(node* pos) {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		n--;
	}

	void eraseFront() {
		erase(begin());
	}

	void eraseBack() {
		erase(end()->prev);
	}
};

/* doubly linked list�� �̿��� list�� ����������, O(n)�� space - complexity�� ������,
	��� ��ɵ��� O(1) time-complexity�� ���´�.
*/
