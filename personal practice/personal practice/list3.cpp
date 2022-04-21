#include <iostream>	

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class nodeList {
private:
	node* head;
	node* tail;
	int n;

public:
	nodeList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	node* begin() {
		return head->next;
	}

	node* end() {
		return tail;
	}

	node* nextP(node* pos) {
		if (pos != end()) {
			return pos->next;
		}
		return pos;
	}

	node* prevP(node* pos) {
		if (pos != begin()) {
			return pos->prev;
		}
		return pos;
	}

	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = pos;
		newNode->prev = pos->prev;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	void insertFront(int data) {
		insert(begin(), data);
	}

	node* erase(node* pos) {
		if (empty()) {
			cout << "Empty" << endl;
			return pos;
		}
		if (pos == end()) {
			return pos;
		}
		pos->next->prev = pos->prev;
		pos->prev->next = pos->next;
		delete pos;
		n--;
		return begin();
	}

	void print() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		node* curNode = begin();
		while (curNode != end()) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}

	void upper(int data) {
		node* curNode = begin();
		int idx = 0;
		bool flag = true;
		while (curNode != end()) {
			if (curNode->data > data) {
				flag = false;;
				cout << idx << " ";
			}
			idx++;
			curNode = curNode->next;
		}
		if (flag) {
			cout << -1;
		}
		cout << endl;
	}
};

int main() {
	int n;
	cin >> n;
	nodeList list;
	node* p = list.begin();
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "begin") {
			p = list.begin();
		}
		if (s == "end") {
			p = list.end();
		}
		if (s == "insert") {
			int x;
			cin >> x;
			list.insert(p, x);
		}
		if (s == "erase") {
			p= list.erase(p);
		}
		if (s == "nextP") {
			p = list.nextP(p);
		}
		if (s == "prevP") {
			p = list.prevP(p);
		}
		if (s == "print") {
			list.print();
		}
		if (s == "upper") {
			int x;
			cin >> x;
			list.upper(x);
		}

	}
}