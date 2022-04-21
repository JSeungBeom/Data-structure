#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class Queue {
private:
	node* frontNode;
	node* rearNode;
	int n;
	
public:
	Queue() {
		frontNode = rearNode = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	void front() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << frontNode->data << endl;
	}

	void rear() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << rearNode->data << endl;
	}

	void enqueue(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			frontNode = rearNode = newNode;
		}
		else {
			rearNode->next = newNode;
			rearNode = newNode;
		}
		n++;
	}

	void dequeue() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		node* curNode = frontNode;
		front();
		if (n == 1) {
			frontNode = rearNode = NULL;
		}
		else {
			frontNode = frontNode->next;
		}
		n--;
		delete curNode;
	}
};

int main() {
	int t;
	cin >> t;
	Queue q;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int data;
		if (s == "size") {
			cout << q.size() << endl;
		}
		if (s == "isEmpty") {
			if (q.empty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if (s == "front") {
			q.front();
		}
		if (s == "rear") {
			q.rear();
		}
		if (s == "enqueue") {
			cin >> data;
			q.enqueue(data);
		}
		if (s == "dequeue") {
			q.dequeue();
		}
	}
}