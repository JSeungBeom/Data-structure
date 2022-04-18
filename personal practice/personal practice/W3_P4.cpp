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

	void push(int data) {
		if (topidx == capacity - 1) {
			return;
		}
		arr[++topidx] = data;
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		topidx--;
		return arr[topidx + 1];
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[topidx];
	}
};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		Stack st(s.length());
		for (int j = 0; j < s.length(); j++) {
			int num = s[j] - '0';
			if (0 < num && num < 10) {
				st.push(num);
			}
			else {
				int a = st.pop();
				int b = st.pop();
				switch (s[j]) {
				case '*':
					st.push(b * a);
					break;
				case '+':
					st.push(b + a);
					break;
				case '-':
					st.push(b - a);
					break;
				}
			}
		}
		cout << st.top() << endl;
	}
}