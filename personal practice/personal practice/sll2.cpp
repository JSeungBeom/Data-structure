#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class SLL {
private:
	node* head;
	node* tail;
	int n;

public:
	SLL() {
		head = tail = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
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
		n++;
		print();
	}

	void insertion(int idx, int data) {
		if (idx < 0 || idx > n) {
			cout << "Index Error" << endl;
			return;
		}
		else if (idx == n) {
			append(data);
		}
		else if (idx == 0) {
			node* newNode = new node;
			newNode->data = data;
			newNode->next = head;
			head = newNode;
			n++;
			print();
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
			n++;
			print();
		}
	}

	void deletion(int idx) {
		if (idx < 0 || idx >= n || empty()) {
			cout << -1 << endl;
			return;
		}
		node* curNode = head;
		if (idx == 0) {
			cout << curNode->data << endl;
			if (n == 1) {
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
			cout << curNode->data << endl;
			preNode->next = curNode->next;
			if (curNode == tail) {
				tail = preNode;
			}
		}
		delete curNode;
		n--;
	}

	void sum() {
		if (empty()) {
			cout << 0 << endl;
			return;
		}
		node* curNode = head;
		int sum = 0;
		while (curNode != NULL) {
			sum += curNode->data;
			curNode = curNode->next;
		}
		cout << sum << endl;
	}
};

int main() {
	int m;
	cin >> m;
	SLL li;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int idx, data;
		if (s == "Print") {
			li.print();
		}
		if (s == "Append") {
			cin >> data;
			li.append(data);
		}
		if (s == "Delete") {
			cin >> idx;
			li.deletion(idx);
		}
		if (s == "Insert") {
			cin >> idx >> data;
			li.insertion(idx, data);
		}
		if (s == "Sum") {
			li.sum();
		}
	}
}

