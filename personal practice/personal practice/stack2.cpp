#include <iostream>

using namespace std;

class Stack {
private:
	char* arr;
	int capacity;
	int topidx;

public:
	Stack(int capacity) {
		this->capacity = capacity;
		arr = new char[capacity];
		topidx = -1;
	}

	int size() {
		return topidx + 1;
	}

	bool empty() {
		return (size() == 0);
	}

	void push(char data) {
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

	char top() {
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
		for (int i = 0; i < s.length(); i++) {
			int num = s[i] - '0';
			if (0 < num && num < 10) {
				cout << num;
			}
			else {
				if (s[i] == '*') {
					while (st.top() == '*') {
						cout << st.top();
						st.pop();
					}
					st.push(s[i]);
				}
				else if (s[i] == '+' || s[i] == '-') {
					while (!st.empty()) {
						cout << st.top();
						st.pop();
					}
					st.push(s[i]);
				}
			}
			if (i == s.length() - 1) {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << endl;
			}
		}
	}
}