#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};
class LinkedList {
private:
	node* head;
	node* tail;
	int n;

public:
	LinkedList() {
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
		else if (idx == 0) {
				node* newNode = new node;
				newNode->data = data;
				newNode->next = head;
				head = newNode;
				n++;
				print();
		}
		else if (idx == n) {
			append(data);
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
			if (n == 1) {
				cout << curNode->data << endl;
				head = tail = NULL;
			}
			else {
				cout << curNode->data << endl;
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

	void min() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		node* curNode = head;
		int min = curNode->data;
		while (curNode != NULL) {
			if (curNode->data < min) {
				min = curNode->data;
			}
			curNode = curNode->next;
		}
		cout << min << endl;
	}
};

int main() {
	int m;
	cin >> m;
	LinkedList li;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int idx, data;
		if (s == "Append") {
			cin >> data;
			li.append(data);
		}
		else if (s == "Print") {
			li.print();
		}
		else if (s == "Delete") {
			cin >> idx;
			li.deletion(idx);
		}
		else if (s == "Insert") {
			cin >> idx >> data;
			li.insertion(idx, data);
		}
		else if (s == "Min") {
			li.min();
		}
	}
}