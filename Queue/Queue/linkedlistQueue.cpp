#include <iostream>

using namespace std;

struct node {
	node* next; // ��ũ
	int data; // ������
};

class listQueue {
private:
	node* frontNode; // ��ũ�� ����Ʈ���� head ����
	node* rearNode; // ��ũ�� ����Ʈ���� tail ����
	int n; // ť�� ������

public:
	listQueue() {
		frontNode = rearNode = NULL;
		n = 0;
	} // ������

	int size() {
		return n;
	} // ť�� ������ ����

	bool empty() {
		return (n == 0);
	} // ť�� ������� �Ǵ�
	
	void front() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << frontNode->data << endl;
	} // front�� ������ ����

	void rear() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << rearNode->data << endl;
	} // rear�� ������ ����

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
	} // ť�� rear�� ������ ����

	void dequeue() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		node* curNode = frontNode;
		cout << curNode->data << endl;
		if (n == 1) {
			frontNode = rearNode = NULL;
		}
		else {
			frontNode = frontNode->next;
		}
		delete curNode;
		n--;
	} // ť�� front���� ������ ����
};

int main() {
	int t;
	cin >> t;
	listQueue q;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (s == "isEmpty") {
			if (q.empty()) {
				cout << "True" << endl;
			}
			else
				cout << "False" << endl;
		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
		else if (s == "enqueue") {
			int data;
			cin >> data;
			q.enqueue(data);
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
	}
}


