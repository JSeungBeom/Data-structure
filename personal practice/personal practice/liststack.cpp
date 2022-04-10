#include <iostream>

using namespace std;

struct node {
	node* next;
	int data;
};
class listStack{
private:
	node* topNode;
	int stacksize;

public:
	listStack() {
		topNode = NULL;
		stacksize = 0;
	}

	int size() {
		return stacksize;
	}

	bool empty() {
		return (size() == 0);
	}

	void push(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = topNode;
		topNode = newNode;
		stacksize++;
	}

	void pop() {
		if (empty()) {
			return;
		}
		node* curNode = topNode;
		topNode = topNode->next;
		delete curNode;
		stacksize--;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return topNode->data;
	}
};

int main() {
	listStack ls;
	ls.push(1);
	ls.push(2);
	ls.push(3);
	cout << ls.top() << endl;
	ls.pop();
	cout << ls.top() << endl;

}