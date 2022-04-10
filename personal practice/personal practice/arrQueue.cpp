#include <iostream>

using namespace std;

class arrQueue {
private:
	int* arr;
	int capacity; // �迭�� �ִ� ũ��
	int frontidx; // ť�� front ��ġ�� �ε���
	int rearidx; // ť�� rear + 1 ��ġ�� �ε���
	int n; // ť�� ũ��

public:
	arrQueue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = n = 0; // �ʱ⿡ frontidx, rearidx ��� 0���� �ʱ�ȭ
	}

	// ť�� ������ ����
	int size() {
		return n;
	}

	// ť�� ������� �Ǵ�
	bool empty() {
		return (n == 0);
	}

	// ť�� rear���� ������ ����
	void enqueue(int data) {
		if (n == capacity) {
			return;
		}
		arr[rearidx] = data; // rear + 1 ��ġ�� rearidx�� data ����
		rearidx = (rearidx + 1) % capacity; // rearidx�� 1 ����, �迭�� ũ�⸦ �Ѿ�� �ٽ� 0���� ����
		n++; // ť ������ ����
	}

	// ť�� front���� ������ ����
	void dequeue() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity; // frontidx�� 1 ����, �迭�� ũ�⸦ �Ѿ�� �ٽ� 0���� ����
		n--; // ť�� ������ ����
	}

	// ť�� front�� data ����
	int front() {
		if (empty()) {
			return -1;
		}
		return arr[frontidx];
	}
};

int main() {
	arrQueue aq(10);
	aq.enqueue(3);
	aq.enqueue(4);
	aq.enqueue(5);
	cout << aq.front() << endl;
	aq.dequeue();
	cout << aq.front() << endl;
}