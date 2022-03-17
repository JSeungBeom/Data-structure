#include <iostream>

using namespace std;

class arraystack {
private:
	int* arr; // stack의 요소를 저장할 배열
	int capacity; // stack의 최대 수용량을 저장
	int topIndex; // stack의 top이 저장된 인덱스를 저장
public:
	arraystack(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		topIndex = -1;
	} // 생성자, capacity를 parameter로 전달받아 배열을 초기화

	bool empty() {
		if (topIndex == -1) {
			return true;
		} // 스택이 비어있는 경우
		else
			return false;
		// 스택이 비어있지 않은 경우
	}

	int size() {
		return topIndex + 1;
	} // 배열의 index는 0부터 시작하므로, topindex + 1이 스택의 크기

	int top() {
		if (empty()) {
			return -1;
		} // 스택이 비었다면, -1 반환
		return arr[topIndex]; // topIndex의 데이터를 반환
	} 

	void push(int data) {
		if (size() == capacity) {
			return;
		} // 스택의 사이즈가, 최대 수용량과 같다면(스택이 가득 찼다면) 리턴
		else
			arr[++topIndex] = data;
		// topIndex를 1 증가시키고 data 삽입
	}

	int pop() {
		if (empty()) {
			return -1;
		} // 스택이 비었다면 -1 반환
		else
			topIndex--;
		// topindex를 1 감소
	}
};
