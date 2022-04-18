#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;

public:
	nodeList() {
		header = new node;
		trailer = new node;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	node* begin() {
		return header->next;
	}

	node* end() {
		return trailer;
	}

	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos;
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
			int max = curNode->data;
			int min = curNode->data;

			if (curNode->prev->data > max &&
				curNode->prev != header) {
				max = curNode->prev->data;
			}
			if (curNode->prev->data < min &&
				curNode->prev != header) {
				min = curNode->prev->data;
			}
			if (curNode->next->data > max
				&& curNode->next != trailer) {
				max = curNode->next->data;
			}
			if (curNode->next->data < min
				&& curNode->next != trailer) {
				min = curNode->next->data;
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
			int data;
			cin >> data;
			list.insertBack(data);
		}
		list.MaxMinusMin();
	}
}