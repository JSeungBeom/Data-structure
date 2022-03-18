#include <iostream>

using namespace std;

class arrayStack {
private:
	int topIndex; // stack�� top ��ġ�� index
 	int* arr; // stack�� ������ �迭
	int capacity; // stack�� �ִ� ũ��

public:
	arrayStack(int capacity) {
		this->capacity = capacity;
		topIndex = -1;
		arr = new int[capacity];
	} // �����ڷ� capacity�� ���޹޾� �迭�� �����, ó������ ������ ��������Ƿ� topIndex = -1

	bool empty() {
		if (topIndex == -1) {
			return true;
		}
		else
			return false;
	} // ����ִٸ� true �ƴ϶�� false�� ��ȯ

	int size() {
		return topIndex + 1;
	} // ������ ����� ��ȯ

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[topIndex];
	} // ����ִٸ� -1�� ��ȯ�ϰ�, �ƴ϶�� topIndex�� ��Ҹ� ��ȯ

	void push(int data) {
		if (size() == capacity) {
			return;
		}
		arr[++topIndex] = data;
	} // capacity�� size()�� �Ѱ�ٸ� �����ϰ�, �ƴ϶�� topIndex�� 1 ������Ű�� ��Ҹ� ����

	void pop() {
		if (empty()) {
			return;
		}
		topIndex--;
	} // ����ִٸ� �����ϰ�, �ƴ϶�� topIndex�� 1 ���ҽ�Ų��
};

int main() {

}