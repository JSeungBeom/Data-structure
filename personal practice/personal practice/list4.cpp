#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
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
		head->prev = tail->next = NULL;
		head->next = tail;
		tail->prev = head;
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

	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = pos;
		newNode->prev = pos->prev;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	void MaxMinusMin() {
		node* curNode = begin();
		while (curNode != end()) {
			int min = curNode->data;
			int max = curNode->data;
			if (curNode->prev->data < min && curNode->prev != head) {
				min = curNode->prev->data;
			}
			if (curNode->prev->data > max && curNode->prev != head) {
				max = curNode->prev->data;
			}
			if (curNode->next->data < min && curNode->next != tail) {
				min = curNode->next->data;
			}
			if (curNode->next->data > max && curNode->next != tail) {
				max = curNode->next->data;
			}
			cout << max - min << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		nodeList list;
		for (int i = 0; i < n; i++) {
			int e;
			cin >> e;
			list.insertBack(e);
		}
		list.MaxMinusMin();
	}
}