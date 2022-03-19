#include <iostream>

using namespace std;

struct node {
	char data; // ������ �ʵ�, ��ȣ�� ������ ���̹Ƿ� char Ÿ��
	node* next; // ��ũ �ʵ�
};

class stack {
private:
	node* topNode; // singlylinkedlist������ head ����
	int listsize; // ���� ������

public:
	stack() {
		topNode = NULL;
		listsize = 0;
	} // ������� �ʱ�ȭ

	int size() {
		return listsize;
	} // ������ ������ ��ȯ

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // ������ ������� �Ǵ�

	bool isUpper(char data1, char data2) {
		if (data1 == '*' || data1 == '/') {
			return true;
		} // ���� �����ڰ� *, / ���ٸ� ������ ���� �����ں��� ũ�� true
		else if (data1 == '+' || data1 == '-') {
			if (data2 == '+' || data2 == '-')
				return true;
			else
				return false;
		} // ���� �����ڰ� +, - ���ٸ� ���� �����ڰ� +, -�̸� true, *, /��� false ��ȯ
		else
			return false;
	} // �����ڰ� ���� �����ں��� ū��, ������ �Ǵ�

	void push(char data) {
		int num = data - '0'; 
		if (num >= 1 && num <= 9) {
			cout << num;
			return;
		} // �����Ͱ� �ǿ������̸� ����ϰ� �Լ� ����
		while (!empty() && isUpper(topNode->data, data)) {
			pop();
		} // ������ �������� ������ �켱 ������ �Ǵ��Ͽ� pop() �Լ� �ݺ� ����
		node* newNode = new node; // �� ���
		newNode->data = data; // ������ ����
		newNode->next = topNode; // �� ����� next�� topNode
		topNode = newNode; // �� ��尡 topNode
		listsize++;  // *����Ʈ����� ����
	}

	void pop() {
		if (empty()) {
			return;
		} // ������ ����ٸ� ����
		node* curNode = topNode; // ������ ���� topNode
		cout << curNode->data; // ������ ����� �����͸� ���
		topNode = topNode->next; // topNode�� topNode�� next
		delete curNode; // ���� topNode�� ����
		listsize--; // *����Ʈ����� ����
	}
};

int main() {
	int t;
	
	cin >> t; // ������ ��

	stack st;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			st.push(s[j]);
			if (j == s.length() - 1) {
				while (!st.empty()) {
					st.pop();
				}
			} // ������ �������Ƿ�, ���ÿ� ���� �����ڸ� ��� pop
		}
		cout << endl;
	}
}