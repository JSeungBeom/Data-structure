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
		header->data = trailer->data = 0;
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
		newNode->next = pos;
		newNode->prev = pos->prev;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	void sum() {
		node* curNode = begin();
		while (curNode != end()) {
			int sum = curNode->prev->data + curNode->data + curNode->next->data;
			cout << sum << " ";
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
		list.sum();
	}
}