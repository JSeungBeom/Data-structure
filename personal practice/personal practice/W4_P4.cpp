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
		if (n == capacity) {
			return;
		}
		arr[rearidx] = data;
		rearidx = (rearidx + 1) % capacity;
		n++;
	}

	void dequeue() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity;
		n--;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return arr[frontidx];
	}

	void add(int diff) {
		arr[frontidx] += diff;
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		Queue p1(n);
		Queue p2(n);
		int win1 = 0;
		int win2 = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			p1.enqueue(x);
		}
		for (int i = 0; i < n; i++) {
			int y;
			cin >> y;
			p2.enqueue(y);
		}
		for (int i = 0; i < n; i++) {
			if (p1.front() > p2.front()) {
				int diff = abs(p1.front() - p2.front());
				win1++;
				cout << "Round" << i + 1 << " P1 " << diff << endl;
				p1.dequeue();
				p2.dequeue();
				p2.add(diff);
			}
			else if (p1.front() < p2.front()) {
				int diff = abs(p1.front() - p2.front());
				win2++;
				cout << "Round" << i + 1 << " P2 " << diff << endl;
				p1.dequeue();
				p2.dequeue();
				p1.add(diff);
			}
			else {
				cout << "Round" << i + 1 << " Draw" << endl;
				p1.dequeue();
				p2.dequeue();
			}
		}
		if (win1 > win2) {
			cout << "Winner P1" << endl;
		}
		else if (win1 < win2) {
			cout << "Winner P2" << endl;
		}
		else {
			cout << "Draw" << endl;
		}
	}
}