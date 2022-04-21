#include <iostream>

using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
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
		head->data = tail->data = 0;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = NULL;
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

	void printsum() {
		node* curNode = begin();
		int sum = 0;
		while (curNode != end()) {
			sum = curNode->prev->data + curNode->data + curNode->next->data;
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
			int e;
			cin >> e;
			list.insertBack(e);
		}
		list.printsum();
	}
}