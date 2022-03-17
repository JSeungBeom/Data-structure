#include <iostream>

using namespace std;

class arraystack {
private:
	int* arr; // stack�� ��Ҹ� ������ �迭
	int capacity; // stack�� �ִ� ���뷮�� ����
	int topIndex; // stack�� top�� ����� �ε����� ����
public:
	arraystack(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		topIndex = -1;
	} // ������, capacity�� parameter�� ���޹޾� �迭�� �ʱ�ȭ

	bool empty() {
		if (topIndex == -1) {
			return true;
		} // ������ ����ִ� ���
		else
			return false;
		// ������ ������� ���� ���
	}

	int size() {
		return topIndex + 1;
	} // �迭�� index�� 0���� �����ϹǷ�, topindex + 1�� ������ ũ��

	int top() {
		if (empty()) {
			return -1;
		} // ������ ����ٸ�, -1 ��ȯ
		return arr[topIndex]; // topIndex�� �����͸� ��ȯ
	} 

	void push(int data) {
		if (size() == capacity) {
			return;
		} // ������ �����, �ִ� ���뷮�� ���ٸ�(������ ���� á�ٸ�) ����
		else
			arr[++topIndex] = data;
		// topIndex�� 1 ������Ű�� data ����
	}

	int pop() {
		if (empty()) {
			return -1;
		} // ������ ����ٸ� -1 ��ȯ
		else
			topIndex--;
		// topindex�� 1 ����
	}
};
