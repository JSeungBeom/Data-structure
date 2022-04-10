#include <iostream>

using namespace std;

class arrStack {
private:
	int* arr;
	int capacity;
	int topidx;

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

		arr[++topidx] = data;
	}

	void pop() {
		if (empty()) {
			return;
		}
		topidx--;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[topidx];
	}
};

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arrStack ar(s.length());
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '*') {
				int temp = ar.top();
				ar.pop();
				int result = ar.top() * temp;
				ar.pop();
				ar.push(result);
			}
			else if (s[j] == '/') {
				int temp = ar.top();
				ar.pop();
				int result = ar.top() / temp;
				ar.pop();
				ar.push(result);
			}
			else if (s[j] == '+') {
				int temp = ar.top();
				ar.pop();
				int result = ar.top() + temp;
				ar.pop();
				ar.push(result);
			}
			else if (s[j] == '-') {
				int temp = ar.top();
				ar.pop();
				int result = ar.top() - temp;
				ar.pop();
				ar.push(result);
			}
			else {
				int num = s[j] - '0';
				ar.push(num);
			}
		}
		cout << ar.top() << endl;
	}
}