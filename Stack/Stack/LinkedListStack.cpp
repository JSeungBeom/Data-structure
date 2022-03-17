#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class stack {
private:
	node* head; // stack���� top�� ��ġ�� �����͸� ������ ���
	node* tail; 
	int listsize; // stack�� ������

public:
	stack() {
		head = NULL;
		tail = NULL;
		listsize = 0;
	} // ��� ���� �ʱ�ȭ
	
	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // ������ ������� �Ǵ�

	int size() {
		return listsize;
	} // ������ ũ�⸦ ����

	void push(int x) {
		node* newNode = new node;
		newNode->data = x;
		// stack�� top�� �߰��� ������
		if (empty()) {
			newNode->next = NULL;
			head = tail = newNode;
		} // stack�� ����ٸ�, head�� tail ��� newNode�� ����
		else {
			newNode->next = head;
			head = newNode;
		} // top(head)�� �����͸� �����ϹǷ�, �� ����� ���� ���� head�� �ǰ�, �� ���� head�� �ȴ�
		listsize++; 
		top();
	} // top�� �����͸� �߰��ϴ� �Լ�

	void pop() {
		if (empty()) {
			cout << "Stack empty" << endl;
			return;
		} // ������ ����ٸ� pop�� ������ �� ����
		else if (size() == 1) {
			cout << head->data << endl;
			head = tail = NULL;
		} // ������ ����� 1�� ���¿���, �����͸� �����ϸ� ������ ����ִ� ���°� �ȴ�
		else {
			cout << head->data << endl;
			node* topNode = head;
			head = head->next;
			delete topNode;
		} // top(head)�� �����͸� �����ϹǷ�, head�� �� ���� ��尡 �ǰ�, head���� ���� �޸� ����
		listsize--;
	}

	void top() {
		cout << head->data << endl;
	} // top�� �����͸� ����ϴ� �Լ�
};

int main() {
	int n;

	cin >> n;

	stack st;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "pop") {
			st.pop();
		}
		else if (s == "top") {
			st.top();
		}
		else if (s == "empty") {
			st.empty();
		}
		else if (s == "size") {
			st.size();
		}
		else
			break;
	}
}

/*
singlylinkedlist�� ������ stack�� ��� ����� head�� top���� �Ͽ��� ��,
O(1)�� �ð� ���⵵�� ����, O(n)�� ���� ���⵵�� �����Ƿ�, ȿ������ �ڷ����̶�� �� �� �ִ�.
*/
