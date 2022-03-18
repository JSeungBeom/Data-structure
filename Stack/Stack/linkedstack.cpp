#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class stack {
private:
	node* topNode;
	int listsize = 0;

public:
	int size() {
		return listsize;
	}

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return topNode->data;
	}

	void push(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = topNode;
		topNode = newNode;
		listsize++;
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
		listsize--;
		
	}
};

int main() {
	int n;

	cin >> n;

	stack st;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "pop") {
			st.pop();
		}
		else if (s == "size") {
			cout << st.size() << endl;
		}
		else if (s == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}
		else if (s == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "top") {
			cout << st.top() << endl;
		}
		else
			break;
	}
}