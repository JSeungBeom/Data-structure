#include <iostream>

using namespace std;

class arrayStack {
private:
	int topIndex; // stack의 top 위치의 index
 	int* arr; // stack을 저장할 배열
	int capacity; // stack의 최대 크기

public:
	arrayStack(int capacity) {
		this->capacity = capacity;
		topIndex = -1;
		arr = new int[capacity];
	} // 생성자로 capacity를 전달받아 배열을 만들고, 처음에는 스택이 비어있으므로 topIndex = -1

	bool empty() {
		if (topIndex == -1) {
			return true;
		}
		else
			return false;
	} // 비어있다면 true 아니라면 false를 반환

	int size() {
		return topIndex + 1;
	} // 스택의 사이즈를 반환

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[topIndex];
	} // 비어있다면 -1을 반환하고, 아니라면 topIndex의 요소를 반환

	void push(int data) {
		if (size() == capacity) {
			return;
		}
		arr[++topIndex] = data;
	} // capacity를 size()가 넘겼다면 종료하고, 아니라면 topIndex를 1 증가시키고 요소를 삽입

	void pop() {
		if (empty()) {
			return;
		}
		topIndex--;
	} // 비어있다면 종료하고, 아니라면 topIndex를 1 감소시킨다
};

int main() {

}