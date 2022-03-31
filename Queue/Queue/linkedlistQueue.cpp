#include <iostream>

using namespace std;

struct node {
	node* next; // 링크
	int data; // 데이터
};

class listQueue {
private:
	node* frontNode; // 링크드 리스트에서 head 역할
	node* rearNode; // 링크드 리스트에서 tail 역할
	int n; // 큐의 사이즈

public:
	listQueue() {
		frontNode = rearNode = NULL;
		n = 0;
	} // 생성자

	int size() {
		return n;
	} // 큐의 사이즈 리턴

	bool empty() {
		return (n == 0);
	} // 큐가 비었는지 판단
	
	void front() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << frontNode->data << endl;
	} // front의 데이터 리턴

	void rear() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << rearNode->data << endl;
	} // rear의 데이터 리턴

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
	} // 큐의 rear에 데이터 삽입

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
	} // 큐의 front에서 데이터 삭제
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


