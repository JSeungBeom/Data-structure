#include <iostream>

using namespace std;

class stack {
private:
	int* arr;
	int topIndex;
	int capacity;

public:
	stack(int capacity) {
		this->capacity = capacity;
		topIndex = -1;
		arr = new int[capacity];
	}

	int size() {
		return topIndex + 1;
	}

	bool empty() {
		if (size() == 0) {
			return true;

		}
		else
			return false;
	}

	void push(char data) {
		int num = data - '0';
		if (0 <= num  && num < 10) {
			arr[++topIndex] = num;
			return;
		}
		else {
			int a = pop();
			int b = pop();
			switch (data) {
			case '+':
				arr[++topIndex] = b + a;
				break;
			case '-':
				arr[++topIndex] = b - a;
				break;
			case '*':
				arr[++topIndex] = b * a;
				break;
			default:
				break;
			}
		}
	}

	int pop() {
		if (topIndex == -1) {
			return -1;
		}
		topIndex--;
		return arr[topIndex + 1];
	}

	int top() {
		return arr[topIndex];
	}
};

int main() {
	int t;

	cin >> t;
	


	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		stack st(s.length());
		for (int j = 0; j < s.length(); j++) {
			st.push(s[j]);
		}
		cout << st.top() << endl;
	}
}