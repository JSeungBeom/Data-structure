#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arrsize;

public:
	// ������
	Array(int arrsize) {
		this->arrsize = arrsize;
		arr = new int[arrsize];
		for (int i = 0; i < arrsize; i++) {
			arr[i] = 0;
		}
	}

	// �迭�� �Ҵ�, idx��° ���� data�� ����
	void set(int idx, int data) {
		if (idx < 0 || idx >= arrsize) {
			return;
		}
		arr[idx] = data;
	}

	// �迭�� ����, arr[idx] ~ arr[n -2]�� ���������� �̵���Ų ��, ����
	void add(int idx, int data) {
		// exception handling
		if (idx < 0 || idx > arrsize) {
			return;
		}
		// �迭�� �� �ں��� ��ҵ��� ���������� �̵�
		for (int i = arrsize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		// ������ ����
		arr[idx] = data;
	}

	// �迭�� ����, arr[idx +1] ~ arr[arrsize - 1]�� �������� �̵�
	void remove(int idx) {
		// exception handling
		if (idx < 0 || idx >= arrsize) {
			return;
		}
		// idx + 1���� arrsize - 1�� �������� �̵�����, ������ ������ ä��
		for (int i = idx + 1; i < arrsize; i++) {
			arr[i - 1] = arr[i];
		}
		// �� ���� �� ������ 0���� ä��
		arr[arrsize - 1] = 0;
	}
	
	// �迭 ���
	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// �迭���� ��ġ�ϴ� ��Ҹ� ã�� �ε��� ���
	void find(int data) {
		for (int i = 0; i < arrsize; i++) {
			if (arr[i] == data) {
				cout << i << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
};

int main() {
	int t, n;
	cin >> t >> n;
	Array arr(n);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int data, idx;
		if (s == "set") {
			cin >> idx >> data;
			arr.set(idx, data);
		}
		else if (s == "add") {
			cin >> idx >> data;
			arr.add(idx, data);
		}
		else if (s == "remove") {
			cin >> idx;
			arr.remove(idx);
		}
		else if (s == "print") {
			arr.print();
		}
		else if (s == "find") {
			cin >> data;
			arr.find(data);
		}
	}
}