#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};
class singlyLinkedList {
private:
	node* head;
	node* tail;
	int listsize;

public:
	singlyLinkedList() {
		head = tail = NULL;
		listsize = 0;
	}
	
	int size() {
		return listsize;
	}
	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	}

	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		listsize++;
	}

	void insertion(int idx, int data) {
		if (idx < 0 || idx > listsize) {
			return;
		}
		else if (idx == size()) {
			append(data);
		}
		else if (idx == 0) {
			node* newNode = new node;
			newNode->data = data;
			newNode->next = head;
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
			curNode->next = newNode;
		}
		listsize++;
	}

	void deletion(int idx) {
		if (idx < 0 || idx >= listsize || empty()) {
			return;
		}
		node* curNode = head;
		if (idx == 0) {
			if (listsize == 1) {
				head = tail = NULL;
			}
			else {
				head = head->next;
			}
		}
		else {
			node* preNode = head;
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			}
			preNode->next = curNode->next;
			if (curNode == tail) {
				tail = preNode;
			}
		}
		delete curNode;
		listsize--;
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
};

int main() {
	singlyLinkedList s;
	s.append(3);
	s.append(4);
	s.print();
	s.insertion(1, 2);
	s.print();
	s.insertion(1, 6);
	s.print();
	s.deletion(1);
	s.print();
}