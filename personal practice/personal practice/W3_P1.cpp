#include <iostream>

using namespace std;

class Stack {
private:
	int* arr;
	int capacity;
	int topidx;

public:
	// »ý¼ºÀÚ
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
		topidx--;
		cout << arr[topidx + 1] << endl;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[topidx];
	}
};

int main() {
	int t, n;
	cin >> t >> n;
	Stack stack(t);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "size") {
			cout << stack.size() << endl;
		}
		else if (s == "empty") {
			if (stack.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "top") {
			cout << stack.top() << endl;
		}
		else if (s == "push") {
			int data;
			cin >> data;
			stack.push(data);
		}
		else if (s == "pop") {
			stack.pop();
		}
	}
}