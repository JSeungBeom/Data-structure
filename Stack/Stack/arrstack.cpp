#include <iostream>

using namespace std;

class stack {
private:
	int* arr; // ������ ������ �迭
	int capacity; // �迭�� �ִ� ũ��
	int topIndex; // ������ top �������� index

public:
	stack(int capacity) {
		this->capacity = capacity; // ���޹��� parameter�� capcity �ʱ�ȭ
		topIndex = -1; // topIndex�� 0���� �����ϹǷ�, -1�� �ʱ�ȭ
		arr = new int[capacity]; // arr�� ���� �迭�� ����
	}

	int size() {
		return topIndex + 1; // ������ ũ��� topIndex + 1
	} // ������ ������

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // ������ ������� �Ǵ��� �Լ�

	int top() {
		if (empty()) {
			return -1;
		} // ������ ����� ���, -1 ��ȯ
		return arr[topIndex]; // topIndex�� ��Ҹ� ��ȯ
	} // ���� ���� �ִ� ��Ҹ� ��ȯ�ϴ� �Լ�

	void push(int data) {
		if (capacity == size()) {
			cout << "FULL" << endl;
			return;
		} // �迭�� ���� ���� ũ�⸦ �Ѿ��, FULL ���
		arr[++topIndex] = data; // topIndex�� 1 ������Ű��, �� index�� data ����
	} // ������ �� ���� ��Ҹ� �߰��ϴ� �Լ�

	int pop() {
		if (empty()) {
			return -1;
		} // ������ ����� ���, -1 ��ȯ
		topIndex--;
		return arr[topIndex + 1]; // return�ϸ� �Լ��� ����ǹǷ�, �ϴ� topIndex�� 1 ���ҽ�Ű�� ���� top�� ��ȯ
	}
};

int main() {
	int t, n;

	cin >> t >> n; // ���� ������ ũ��, ��ɾ��� ��

	stack st(t); // ��ü ����

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "top") {
			cout << st.top() << endl;
		}
		else if (s == "size") {
			cout << st.size() << endl;
		}
		else if (s == "push") {
			int data;
			cin >> data;
			st.push(data);
		}
		else if (s == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}
		else if (s == "pop") {
			cout << st.pop() << endl;
		}
		else
			break;
	}
}