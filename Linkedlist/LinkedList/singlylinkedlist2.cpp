#include <iostream>

using namespace std;

struct node {
	int data; // �������� data�� ������ ����
	node* next; // ���� node�� ����ų ����
};

class singlylinkedlist {
private:
	node* head; // ����Ʈ�� ó���� ����ų ����
	node* tail; // ����Ʈ�� �������� ����ų ����
	int listsize; // ����Ʈ�� ũ��

public:
	singlylinkedlist() {
		head = NULL;
		tail = NULL;
		listsize = 0;
	}
	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // ����Ʈ�� ����ٸ� true �ƴ϶�� false�� ��ȯ

	void append(int x) {
		node* newNode = new node;
		newNode->data = x;
		newNode->next = NULL;
		if (empty()) {
			head = tail = newNode;
		} // ����Ʈ�� ����ٸ�, head�� tail ��� newNode�� ����Ű�� �ȴ�
		else {
			tail->next = newNode;
			tail = newNode;
		} // ������� �ʴٸ�, tail�� �ڿ� newNode�� �����ϹǷ� tail�� next�� newNode�� �ǰ�, ���ο� tail�� newNode�� �ȴ�
		listsize++; // node�� �߰��Ͽ����Ƿ�, listsize�� ������Ų��
		print(); // ������ �������Ƿ�, ����Ʈ�� ���
	}

	void print() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = head; // head���� ���ʴ�� �����͸� ���
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		} // curNode�� NULL�� �� ������, �����͸� ����ϰ� ���� node�� ����
		cout << endl;
	} // ����Ʈ ���

	void deletion(int idx) {
		if (idx < 0 || idx >= listsize || empty()) {
			cout << -1 << endl;
			return;
		} // �ε����� 0���� �۰ų�, listsize �̻��̰ų�, ����Ʈ�� ����ִٸ� -1�� ����ϰ� return
		node* curNode = head;
		if (idx == 0) {
			if (listsize == 1) {
				cout << head->data << endl;
				head = tail = NULL;
			} // ù��°�� �����͸� �����ϸ� listsize�� 0�� �Ǵ� ����̹Ƿ�, head�� tail�� NULL�� �ȴ�
			else {
				cout << head->data << endl;
				head = head->next;
			} // ù��°�� �����͸� �����ϸ�, head�� head�� next�� �ȴ�
		}
		else {
			node* preNode = head; // curNode�� ���� node�� ������ ������ ����
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			} // idx - 1���� �ݺ��ϸ�, ���������� preNode�� curNode�� ���� ��尡 �ǰ�, �����ϰ��� �ϴ� index�� curNode�� �ȴ�
			cout << curNode->data << endl;
			preNode->next = curNode->next; // preNode�� next�� curNode�� �����ǰ�, curNode�� next�� ����Ų��
			if (curNode == tail) {
				tail = preNode;
			} // ������ node�� tail�̾��ٸ�, preNode�� tail�� �Ǿ��Ѵ�
		}
		delete curNode;
		listsize--;
	}

	void insertion(int idx, int data) {
		if (idx < 0 || idx > listsize) {
			cout << "Index Error" << endl;
			return;
		} // �����ϰ��� �ϴ� ��ġ��, ����Ʈ�� ��� ������ ��� index error ���
		else if (listsize == idx) {
			append(data);
		} // ����Ʈ������� �ε����� ���ٸ�, tail �ڿ� �����͸� �����ϴ� append() �Լ��� �����Ű�� �Ͱ� �����ϴ�
		else {
			if (idx == 0) {
				node* newNode = new node; // ���� �����ϴ� ���
				newNode->data = data; // ����� ������
				newNode->next = head; // ����� next�� head
				head = newNode; // head�� newNode�� ����
				listsize++;
				print();
			} // �����ϰ��� �ϴ� index�� 0�̶��, ���� �����ϴ� node�� next�� head�� �ǰ�, head�� node�� ����
			else {
				node* newNode = new node;
				node* curNode = head;
				newNode->data = data;
				for (int i = 1; i < idx; i++) {
					curNode = curNode->next;
				} // �����ϰ��� �ϴ� ��ġ�� ã�� ���ؼ� index��ġ�� ��带 Ž��
				newNode->next = curNode->next; // newNode�� next�� curNode�� next�� ����Ų��
				curNode->next = newNode; // curNode�� next�� newNode�� �ȴ�
				listsize++;
				print();
			}
		}

	}
	
	void sum() {
		if (empty()) {
			cout << 0 << endl;
			return;
		} // ����ִٸ� 0 ����ϰ� ����
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

	singlylinkedlist li;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int data, index;
		if (s == "Append") {
			cin >> data;
			li.append(data);
		}
		else if (s == "Delete") {
			cin >> index;
			li.deletion(index);
		}
		else if (s == "Print") {
			li.print();
		}
		else if (s == "Insert") {
			cin >> index >> data;
			li.insertion(index, data);
		}
		else if (s == "Sum") {
			li.sum();
		}
		else
			break;
	}

}