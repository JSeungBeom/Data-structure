#include <iostream>

using namespace std;

struct node {
	int data; // ��忡 ����� ������
	node* next; // ���� ��带 ����ų ������
	node* prev; // ���� ��带 ����ų ������
};
class doublylinkedlist {
private:
	node* header; // �� ���� ��带 ����ų ������
	node* trailer; // �� �� ��带 ����ų ������
	int listsize; // ����Ʈ�� ũ��

public:
	doublylinkedlist() {
		header = NULL;
		trailer = NULL;
		listsize = 0;
	} // ��� ���� �ʱ�ȭ

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
	} // ����Ʈ ��� �Լ�

	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // �迭�� ������� �Ǵ��ϴ� �Լ�

	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			newNode->prev = NULL;
			header = trailer = newNode;
		}
		else {
			trailer->next = newNode; // ���� trailer�� next�� newNode�� �Ǿ��Ѵ�
			newNode->prev = trailer;// newNode�� prev�� ������ trailer�̴�
			trailer = newNode; // trailer�� newNode�� �Ҵ�ȴ�
		} // newNode�� tail �ڿ� �߰�
		listsize++;
		print();
	}

	void deletion(int idx) {
		if (idx < 0 || idx >= listsize || empty()) {
			cout << -1 << endl;
			return;
		} // ����Ʈ�� ũ�⺸�� �۰ų�, ũ�ų�, ����Ʈ�� ����ִٸ� -1 ���
		node* curNode = header;
		if (idx == 0) {
			if (listsize == 1) {
				cout << header->data << endl;
				header = trailer = NULL;
			} // ���������� ����Ʈ�� ��ԵǹǷ�, header�� trailer�� NULL�� �ȴ�
			else {
				cout << header->data << endl;
				header = header->next;
				header->prev = NULL;
			} // 0��° ��带 �����ϹǷ�, header�� �� ���� ��尡 �ȴ�. header->prev�� NULL�� �ٽ� �ʱ�ȭ ������Ѵ�
		}
		else{
			node* preNode = header;
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;

			}

			if (curNode == trailer) {
				cout << trailer->data << endl;
				trailer = trailer->prev;
				trailer->next = NULL;
				listsize--;
				return;
			} // curNode�� trailer��� trailer�� curNode�� ���� ��尡 �ǰ�, trailer�� ���� ���� NULL�� �ʱ�ȭ
			cout << curNode->data << endl;
			curNode->next->prev = preNode; // curNode�� ���� ����� ���� ���� preNode�� �ȴ�
			preNode->next = curNode->next; // preNode�� ���� ���� curNode�� ���� ��尡 �ȴ�
		}
		delete curNode;
		listsize--;
	} 

	void print_reverse() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = trailer;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode ->prev;
		}
		cout << endl;
	}// doublylinkedlist�� prev�� �̿��Ͽ� �ݴ�� ����ϴ� �Լ�

	void max() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = header;
		int max = curNode->data;
		while (curNode != NULL) {
			if (max < curNode->data) {
				max = curNode->data;
			}
			curNode = curNode->next;
		}
		cout << max << endl;
	}
}; // ����Ʈ �� �ִ��� ���

int main() {
	int m;
	doublylinkedlist d;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int idx, data;
		if (s == "Print_reverse") {
			d.print_reverse();
		}
		else if (s == "Print") {
			d.print();
		}
		else if (s == "Append") {
			cin >> data;
			d.append(data);
		}
		else if (s == "Delete") {
			cin >> idx;
			d.deletion(idx);
		}
		else if (s == "Max") {
			d.max();
		}
		else
			break;
	}
}