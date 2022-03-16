#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class doublylinkedlist {
private:
	node* header;
	node* trailer;
	int listsize;

public:
	doublylinkedlist() {
		header = NULL;
		trailer = NULL;
		listsize = 0;
	}
	bool empty() {
		if (listsize == 0)
			return true;
		else
			return false;
	}

	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			header = trailer = newNode;
			header->prev = NULL;
			trailer->next = NULL;
		}
		else {
			newNode->prev = trailer;
			trailer->next = newNode;
			trailer = newNode;
		} 
		listsize++;
		print();
	}

	void deletion(int idx) {
		if (idx < 0 || idx >= listsize || empty()) {
			cout << -1 << endl;
			return;
		}
		node* curNode = header;
		if (idx == 0) {
			if (listsize == 1) {
				cout << header->data << endl;
				header = trailer = NULL;
			}
			else {
				cout << header->data << endl;
				header = header->next;
				header->prev = NULL;
			}
		}
		else {
			node* preNode = header;
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			}
			cout << curNode->data << endl;
			if (curNode->next == NULL) {
				trailer = preNode;
				trailer->next = NULL;
				delete curNode;
				listsize--;
				return;
			}
			else {
				curNode->next->prev = preNode;
				preNode->next = curNode->next;
			}
		}
		delete curNode;
		listsize--;
	}

	void print() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = header;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}

	void print_reverse() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = trailer;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	}

	void update(int x, int y) {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		int cnt = 0;
		node* curNode = header;
		while (curNode != NULL) {
			if (curNode->data == x) {
				curNode->data = y;
			}
			else
				cnt++;
			curNode = curNode->next;
		}
		if (cnt == listsize) {
			cout << "Not found\n";
			return;
		}
		print();
	}
};
int main() {
	int m;
	cin >> m;
	doublylinkedlist li;

	for (int i = 0; i < m; i++) {
		string s;

		cin >> s;
		int data, idx, x, y;

		if (s == "Print") {
			li.print();
		}
		else if (s == "Append") {
			cin >> data;
			li.append(data);

		}
		else if (s == "Delete") {
			cin >> idx;
			li.deletion(idx);
		}
		else if (s == "Print_reverse") {
			li.print_reverse();
		}
		else if (s == "Update") {
			cin >> x >> y;
			li.update(x, y);
		}
		else
			break;
	}
}