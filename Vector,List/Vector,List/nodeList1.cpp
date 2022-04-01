#include <iostream>

using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};
class nodeList {
private:
	node* trailer;
	node* header;
	int n;

public:
	// ������, ��� ���� �ʱ�ȭ
	nodeList() {
		trailer = new node;
		header = new node;
		header->next = trailer;;
		trailer->prev = header; // header�� trailer�� ���θ� ����Ű�� ����
		header->prev = trailer->next = NULL;
		n = 0;
	}
	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	// header�� next�� ����
	node* begin() {
		return header->next;
	}

	// trailer�� �ּҰ��� ����
	node* end() {
		return trailer;
	}
	
	// pos�� ���� ���� �̵�
	node* nextP(node* pos) {
		if (pos != end()) {
			return pos->next;
		}
		else
			return pos;
	}

	// pos�� ���� ���� �̵�
	node* prevP(node* pos) {
		if (pos != begin())
			return pos->prev;
		else
			return pos;
	}

	// pos�� data ����
	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = pos;
		newNode->prev = pos->prev; // newNode�� ��,�ڷ� ��� ����
		pos->prev->next = newNode;
		pos->prev = newNode; // ���� ���� newNode ����
		n++;
	}

	// list�� begin()�� data ����
	void insertFront(int data) {
		insert(begin(), data);
	}

	// list�� end()�� prev�� data ����
	void insertBack(int data) {
		insert(end()->prev, data);
	}

	node* erase(node* pos) {
		if (empty()) {
			cout << "Empty" << endl;
			return pos;
		}
		if (pos == end()){
			return pos;
		}
		pos->next->prev = pos->prev;
		pos->prev->next = pos->next; // pos�� ��, �� ��带 ����
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

	void find(int data) {
		node* curNode = begin();
		bool flag = false;
		int num = 0;
		while (curNode != end()) {
			if (curNode->data == data) {
				cout << num << " ";
				flag = true;
			}
			num++;
			curNode = curNode->next;
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
	node* p = list.begin();

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
		else if (s == "find") {
			int data;
			cin >> data;
			list.find(data);
		}
		else
			break;
	}
}