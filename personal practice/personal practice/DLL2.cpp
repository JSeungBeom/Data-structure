#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class DLL {
private:
	node* head;
	node* tail;
	int n;
	
public:
	DLL() {
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
			preNode->next = curNode->next;
			curNode->next->prev = preNode;
		}
		n--;
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
	DLL li;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int data, idx;
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
		if (s == "Print_reverse") {
			li.print_reverse();
		}
		if (s == "Max") {
			li.max();
		}
	}
}