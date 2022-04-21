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
		if (size() == capacity) {
			return;
		}
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
	int t;
	cin >> t;
	for (int j = 0; j < t; j++) {
		string s;
		cin >> s;
		Stack st(s.length());
		int temp, result;
		for (int i = 0; i < s.length(); i++) {
			int num = s[i] - '0';
			if (num > 0 && num < 10) {
				st.push(num);
			}
			else {
				switch (s[i]) {
				case '*':
					temp = st.top();
					st.pop();
					result = st.top() * temp;
					st.pop();
					st.push(result);
					break;
				case '+':
					temp = st.top();
					st.pop();
					result = st.top() + temp;
					st.pop();
					st.push(result);
					break;
				case '-':
					temp = st.top();
					st.pop();
					result = st.top() - temp;
					st.pop();
					st.push(result);
					break;
				}
			}
		}
		cout << st.top() << endl;
	}
}