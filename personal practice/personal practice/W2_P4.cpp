#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class doublyLinkedList {
private:
	node* head;
	node* tail;
	int n;

public:
	doublyLinkedList() {
		head = tail = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			newNode->prev = NULL;
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		n++;
		print();
	}

	void deletion(int idx) {
		if (empty() || idx < 0 || idx >= n) {
			cout << -1 << endl;
			return;
		}
		node* curNode = head;
		if (idx == 0) {
			if (n == 1) {
				cout << curNode->data << endl;
				head = tail = NULL;
			}
			else {
				cout << curNode->data << endl;
				head = head->next;
				head->prev = NULL;
			}
		}
		else {
			node* preNode = head;
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			}
			cout << curNode->data << endl;
			if (curNode == tail) {
				preNode->next = NULL;
				tail = preNode;
				n--;
				return;
			}
			curNode->next->prev = preNode;
			preNode->next = curNode->next;
		}
		delete curNode;
		n--;
	}

	void print() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		node* curNode = head;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	void print_reverse() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		node* curNode = tail;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	}

	void max() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		node* curNode = head;
		int max = curNode->data;
		while (curNode != NULL) {
			if (curNode->data > max) {
				max = curNode->data;
			}
			curNode = curNode->next;
		}
		cout << max << endl;
	}
};

int main() {
	int m;
	cin >> m;
	doublyLinkedList li;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s == "Print") {
			li.print();
		}
		else if (s == "Append") {
			int data;
			cin >> data;
			li.append(data);
		}
		else if (s == "Delete") {
			int idx;
			cin >> idx;
			li.deletion(idx);
		}
		else if (s == "Print_reverse") {
			li.print_reverse();
		}
		else if (s == "Max") {
			li.max();
		}
	}
}