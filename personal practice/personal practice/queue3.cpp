#include <iostream>	

using namespace std;

class Queue {
private:
	int* arr;
	int capacity;
	int frontidx;
	int rearidx;
	int n;

public:
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = n = 0;
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
		cout << arr[frontidx] << endl;
	}

	void rear() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		int idx = rearidx - 1;
		if (idx == -1) {
			idx = capacity - 1;
		}
		cout << arr[idx] << endl;
	}

	void enqueue(int data) {
		if (n == capacity) {
			cout << "Full" << endl;
			return;
		}
		arr[rearidx] = data;
		rearidx = (rearidx + 1) % capacity;
		n++;
	}

	void dequeue() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		front();
		frontidx = (frontidx + 1) % capacity;
		n--;
	}
};

int main() {
	int n, t;
	cin >> n >> t;
	Queue q(n);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
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
			int data;
			cin >> data;
			q.enqueue(data);
		}
		if (s == "dequeue") {
			q.dequeue();
		}
	}
}