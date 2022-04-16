#include <iostream>

using namespace std;

// ��� ����ü
struct node {
	int data; // ������ �ʵ�
	node* next; // ��ũ �ʵ�
};

class singlyLinkedList {
private:
	node* head; // ����Ʈ�� �� �� ���
	node* tail; // ����Ʈ�� �� �� ���
	int n; // ����Ʈ�� ũ��

public:
	// ������
	singlyLinkedList() {
		head = tail = NULL;
		n = 0;
	}

	// ����Ʈ�� ũ�� ����
	int size() {
		return n;
	}
	
	// ����Ʈ�� ������� �Ǵ�
	bool empty() {
		return (n == 0);
	}

	// ����Ʈ�� tail �ڿ� ��� ����
	void append(int data) {
		node* newNode = new node; // ���ο� ��� �Ҵ�
		newNode->data = data; // ������ ����
		newNode->next = NULL; // tail�� �����ϴ�, next�� NULL
		// �� ����Ʈ�� ������ ��
		if (empty()) {
			head = tail = newNode; 
		}
		else {
			tail->next = newNode; // tail�� next�� newNode
			tail = newNode; // tail�� newNode�� ������Ʈ
		}
		n++; // ����Ʈ ������ ����
		print();
	}

	// ����Ʈ�� ��� ����
	void insertion(int idx, int data) {
		// exception handling
		if (idx < 0 || idx > n) {
			cout << "Index Error" << endl;
			return;
		}
		// idx�� ����Ʈ�� ũ��� ���� ��, append�Լ��� ����
		else if (idx == n) {
			append(data);
		}
		// idx �� 0�� ��, head �տ� ����
		else if (idx == 0) {
			node* newNode = new node;
			newNode->data = data;
			newNode->next = head; // newNode�� next�� head
			head = newNode; // newNode�� ���ο� head
			n++;
			print();
		}
		else {
			node* newNode = new node;
			newNode->data = data;
			node* curNode = head;
			for (int i = 1; i < idx; i++) {
				curNode = curNode->next;
			}
			newNode->next = curNode->next;
			curNode->next = newNode;
			n++;
			print();
		}
	}

	// ����Ʈ���� ��� ����
	void deletion(int idx) {
		if (idx < 0 || idx >= n || empty()) {
			cout << -1 << endl;
			return;
		}
		node* curNode = head;
		if (idx == 0) {
			if (n == 1) {
				cout << curNode->data << endl;
				head = tail = NULL;
			}
			else {
				cout << curNode->data << endl;
				head = head->next;
			}
		}
		else {
			node* preNode = head;
			// ��ũ�帮��Ʈ���� �ε����� �־��� ���(tail������ ����) O(n) �ð��� �ɸ���.
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			}
			cout << curNode->data << endl;
			preNode->next = curNode->next;
			if (curNode == tail) {
				tail = preNode;
			}
		}
		n--;
	}

	void print() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		node* curNode = head;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}

	void sum() {
		if (empty()) {
			cout << 0 << endl;
			return;
		}
		int sum = 0;
		node* curNode = head;
		while (curNode != NULL) {
			sum += curNode->data;
			curNode = curNode->next;
		}
		cout << sum << endl;
	}
};

int main() {
	int m;
	cin >> m;
	singlyLinkedList li;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int idx, data;
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
		else if (s == "Insert") {
			cin >> idx>> data;
			li.insertion(idx,data);
		}
		else if (s == "Sum") {
			li.sum();
		}
	}
}

/*
	LinkedList : Concrete data structure consisting of a sequence of nodes
	Each node stores element, link to the next node
	head������ ����: O(1) time newNode->next = head; head = newNode;
	head������ ����: O(1) time head = head->next;
	tail������ ����: O(1) time tail->next = newNode; tail = newNode;
	tail������ ����: O(n) time tail ���� ��带 ã�� ����, indexing�� �ʿ�(not efficient)
	���� ���⵵ : O(n)
*/