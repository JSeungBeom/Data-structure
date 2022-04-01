#include <iostream>

using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;

public:
	// ������, �ʱ� ���´� header�� trailer ��尡 ���� ����� ����
	nodeList() {
		header = new node;
		trailer = new node;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	// list�� ũ�� ����
	int size() {
		return n;
	}

	// list�� ������� Ȯ��
	bool empty() {
		return (n == 0);
	}

	// list�� header�� next �ּҰ� ����
	node* begin() {
		return header->next;
	}

	// list�� trailer�� �ּҰ� ����
	node* end() {
		return trailer;
	}

	// list�� pos �տ� data�� ����
	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = pos;
		newNode->prev = pos->prev; // newNode�� �� �� ��忡 ���� ����
		pos->prev->next = newNode;
		pos->prev = newNode; // �� �� ��带 newNode�� ����
		n++;
	}

	// list�� pos�� ����
	node* erase(node* pos) {
		if (empty()) {
			cout << "Empty" << endl;
			return pos; 
		}
		if (pos == end()) {
			return pos;
		}
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev; // pos�� �� �� ��带 ���� ����
		delete pos; // pos ����
		n--;
		return begin(); // p�� �ּҰ��� �ٽ� begin()���� �ʱ�ȭ
	}

	// p�� ���� ���� �̵�
	node* nextP(node* p) {
		if (p != end())
			return p->next;
		else
			return p;
	}

	// p�� ���� ���� �̵�
	node* prevP(node* p) {
		if (p != begin())
			return p->prev;
		else
			return p;
	}

	// ����Ʈ�� ��ҵ��� ���
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

	// data���� ū ��ҵ��� �ε����� ����Ʈ���� ���
	void upper(int data) {
		node* curNode = begin();
		bool flag = false;
		int idx = 0;
		while (curNode != end()) {
			if (curNode->data > data) {
				cout << idx << " ";
				flag = true;
			}
			curNode = curNode->next;
			idx++;
		}
		if (flag == false) {
			cout << -1;
		}
		cout << endl;
	}
};
int main() {
	int n;

	cin >> n;
	nodeList list;
	node* p = list.begin(); // p�� �ʱⰪ�� begin()

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "begin") {
			p = list.begin();
		}
		else if (s == "end") {
			p = list.end();
		}
		else if (s == "insert") {
			int data;
			cin >> data;
			list.insert(p, data);
		}
		else if (s == "erase") {
			p = list.erase(p);
		}
		else if (s == "nextP") {
			p = list.nextP(p);
		}
		else if (s == "prevP") {
			p = list.prevP(p);
		}
		else if (s == "print") {
			list.print();
		}
		else if (s == "upper") {
			int data;
			cin >> data;
			list.upper(data);
		}
		else
			break;
	}
}