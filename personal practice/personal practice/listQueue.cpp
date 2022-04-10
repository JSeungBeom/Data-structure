#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class listQueue {
private:
	node* frontNode; // 데이터의 삭제가 이루어질 front
	node* rearNode; // 데이터의 삽입이 이루어질 rear
	int n;

public:
	listQueue() {
		frontNode = rearNode = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
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
			return;
		}
		node* curNode = frontNode;
		if (size() == 1) {
			frontNode = rearNode = NULL;
		}
		else {
			frontNode = frontNode->next;
		}
		delete curNode;
		n--;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return frontNode->data;
	}
};

int main() {
	listQueue lq;
	lq.enqueue(3);
	lq.enqueue(4);
	lq.enqueue(5);
	cout << lq.front() << endl;
	lq.dequeue();
	cout << lq.front() << endl;
}