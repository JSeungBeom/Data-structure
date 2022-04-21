#include <iostream>

using namespace std;

class Stack {
private:
	int* arr;
	int capacity;
	int topidx;

public:
	Stack(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		topidx = -1;
	}

	int size() {
		return topidx + 1;
	}

	bool empty() {
		return (size() == 0);
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[topidx];
	}

	void push(int data) {
		if (size() == capacity) {
			cout << "FULL" << endl;
			return;
		}
		arr[++topidx] = data;
	}

	void pop() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		cout << top() << endl;
		topidx--;
	}
};

int main() {
	int t, n;
	cin >> t >> n;
	Stack st(t);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int data;
		if (s == "size") {
			cout << st.size() << endl;
		}
		if (s == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		if (s == "top") {
			cout << st.top() << endl;
		}
		if (s == "push") {
			cin >> data;
			st.push(data);
		}
		if (s == "pop") {
			st.pop();
		}
	}
}