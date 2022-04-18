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

	void enqueue(int data) {
		if (size() == capacity) {
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
		cout << arr[frontidx] << endl;
		frontidx = (frontidx + 1) % capacity;
		n--;
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
		if (rearidx == 0) {
			cout << arr[capacity - 1] << endl;
		}
		else
		cout << arr[rearidx - 1] << endl;
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
		else if (s == "isEmpty") {
			if (q.empty()) {
				cout << "True" << endl;
			}
			else
				cout << "False" << endl;
		}
		else if (s == "enqueue") {
			int data;
			cin >> data;
			q.enqueue(data);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
	
	}
}

/*
	Algorithm enqueue(obj)
	if(size() = N -1) then
	throw QueueFull
	else
	Q[r] <- obj
	r <- (r + 1) mod N
	n <- n + 1
*/