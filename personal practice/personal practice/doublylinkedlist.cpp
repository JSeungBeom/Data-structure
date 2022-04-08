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
	}

	void insertion(int idx, int data) {
		if (idx < 0 || idx > n) {
			return;
		}
		else if (idx == n) {
			append(data);
		}
		else if (idx == 0) {
			node* newNode = new node;
			newNode->data = data;
			newNode->next = head;
			newNode->prev = NULL;
			head->prev = newNode;
			head = newNode;
		}
		else {
			node* newNode = new node;
			newNode->data = data;
			node* curNode = head;
			for (int i = 1; i < idx; i++) {
				curNode = curNode->next;
			}
			newNode->next = curNode->next;
			newNode->prev = curNode;
			curNode->next->prev = newNode;
			curNode->next = newNode;
		}
		n++;
	}

	void deletion(int idx) {
		if (idx < 0 || idx >= n || empty()) {
			return;
		}
		node* curNode = head;
		if (idx == 0) {
			if (n == 1) {
				head = tail = NULL;
			}
			else {
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
			if (curNode == tail) {
				preNode->next = NULL;
				tail = preNode;
				n--;
				return;
			}
			preNode->next = curNode->next;
			curNode->next->prev = preNode;
		}
		n--;
	}

	void print() {
		if (empty()) {
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
			return;
		}
		node* curNode = tail;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	}
};

int main() {
	doublyLinkedList s;
	s.append(3);
	s.append(4);
	s.print();
	s.insertion(1, 2);
	s.print();
	s.insertion(1, 6);
	s.print();
	s.deletion(1);
	s.deletion(0);
	s.print();
	s.print_reverse();
}