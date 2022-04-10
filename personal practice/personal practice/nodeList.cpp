#include <iostream>
#include <list>
using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};

class nodeList {
private:
	node* head;
	node* tail;
	int n;

public:
	nodeList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = NULL; // head�� tail�� ���θ� ����Ű�� �ִ� ����
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	node* begin() {
		return head->next;
	}

	node* end() {
		return tail;
	}

	// pos�� �տ� data�� ����
	void insert(node* pos, int data) {
		node* newNode = new node();
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos; // �Ŵ޸� ����
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
		if (empty()) {
			return;
		}
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
// O(n)�� �������⵵, �� ������ O(1) time�� ����

int main() {

}