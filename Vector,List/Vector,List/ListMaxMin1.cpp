#include <iostream>

using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
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
		header->data = trailer->data = 0;
		n = 0;
	}

	bool empty() {
		return (n == 0);
	}
	
	int size() {
		return n;
	}

	node* begin() {
		return header->next;
	}

	node* end() {
		return trailer;
	}
	void insertBack(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = end();
		newNode->prev = end()->prev;
		end()->prev->next = newNode;
		end()->prev = newNode;
		n++;
	}

	void print() {
		node* curNode = begin();
		while (curNode != end()) {
			int sum = 0;
			sum += curNode->data;
			sum += curNode->prev->data;
			sum += curNode->next->data;
			cout << sum << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int size;
		cin >> size;
		nodeList list;
		for (int j = 0; j < size; j++) {
			int data;
			cin >> data;
			list.insertBack(data);
		}
		list.print();
	}
}