#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class Stack {
private:
	node* topNode;
	int n;

public:
	Stack() {
		topNode = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	void push(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = topNode;
		topNode = newNode;
		n++;
	}

	void pop() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		cout << topNode->data << endl;
		node* curNode = topNode;
		topNode = topNode->next;
		delete curNode;
		n--;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return topNode->data;
	}
};

int main() {
	int n;
	cin >> n;
	Stack st;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "size") {
			cout << st.size() << endl;
		}
		else if (s == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "push") {
			int data;
			cin >> data;
			st.push(data);
		}
		else if (s == "pop") {
			st.pop();
		}
		else if (s == "top") {
			cout << st.top()  << endl;
		}
	}
}