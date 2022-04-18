#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;
	
public:
	nodeList() {
		header = new node;
		trailer = new node;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	node* begin() {
		return header->next;
	}

	node* end() {
		return trailer;
	}

	node* nextP(node* pos) {
		if (pos != end()) {
			return pos->next;
		}
		else
			return pos;
	}

	node* prevP(node* pos) {
		if (pos != begin()) {
			return pos->prev;
		}
		else
			return pos;
	}

	// * pos 앞에 데이터(노드) 삽입
	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	node* erase(node* pos) {
		if (empty()) {
			cout << "Empty" << endl;
			return pos;
		}

		if (pos == end()) {
			return pos;
		}

		node* delNode = pos;
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete delNode;
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
		int idx = 0;
		bool flag = true;
		node* curNode = begin();
		while (curNode != end()) {
			if (curNode->data > data) {
				flag = false;
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
			int data;
			cin >> data;
			list.insert(p, data);
		}
		if (s == "erase") {
			p = list.erase(p);
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
			int data;
			cin >> data;
			list.upper(data);
		}
	}
}