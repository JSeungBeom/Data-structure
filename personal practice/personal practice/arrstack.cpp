#include <iostream>

using namespace std;

class arrStack {
private:
	int* arr;
	int topidx;
	int capacity;

public:
	arrStack(int capacity) {
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
			cout << "Stack Full" << endl;
			return;
		}
		arr[++topidx] = data;
	}

	void pop() {
		if (empty()) {
			cout << "Stack Empty" << endl;
			return;
		}
		topidx--;
	}

	int top() {
		return arr[topidx];
	}
};

int main() {
	arrStack as(10);
	as.push(1);
	as.push(2);
	as.push(3);
	cout << as.top() << endl;
	as.pop();
	cout << as.top() << endl;
}