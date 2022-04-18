#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};
class List {
private:
	node* head;
	node* tail;
	int n;

public:
	List() {
		head = new node();
		tail = new node();
		head->prev = tail->next = NULL;
		head->next = tail;
		tail->prev = head;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
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

	// Iterator(반복자)
	node* begin() {
		return head->next;
	}

	node* end() {
		return tail;
	}

	// pos의 앞쪽에 data 삽입
	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = pos;
		newNode->prev = pos->prev;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertFront(int data) {
		insert(begin(), data);
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	node* erase(node* pos) {
		if (empty()) {
			cout << "Empty" << endl;
			return pos;
		}
		if (pos == tail) {
			return pos;
		}
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		n--;
		return begin();
	}

	void eraseFront() {
		erase(begin());
	}

	void eraseBack() {
		erase(end()->prev);
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

	void find(int data) {
		int idx = 0;
		bool flag = true;
		node* curNode = begin();
		while (curNode != end()) {
			if (curNode->data == data) {
				flag = false;
				cout << idx << " ";
			}
			idx++;
			curNode = curNode->next;
		}
		if (flag) {
			cout << -1 << endl;
		}
		else {
			cout << endl;
		}
	}
};

int main() {
	int n;
	cin >> n;
	List li;
	node* p = li.begin();
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "begin") {
			p = li.begin();
		}
		else if (s == "end") {
			p = li.end();
		}
		else if (s == "insert") {
			int data;
			cin >> data;
			li.insert(p, data);
		}
		else if (s == "erase") {
			p = li.erase(p);
		}
		else if (s == "nextP") {
			p = li.nextP(p);
		}
		else if (s == "prevP") {
			p = li.prevP(p);
		}
		else if (s == "print") {
			li.print();
		}
		else if (s == "find") {
			int data;
			cin >> data;
			li.find(data);
		}
	}
}