#include <iostream>

using namespace std;

struct node {
	int data; // 데이터 필드
	node* next; // 링크 필드
};

class listStack {
private:
	node* topNode; // linkedlist의 head 역할
	int listsize; // 스택의 크기를 저장

public:
	listStack() {
		topNode = NULL;
		listsize = 0;
	} // 멤버 변수 초기화

	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // 스택이 비어있는지 판단

	int size() {
		return listsize;
	} // 스택의 크기를 반환

	int top() {
		if (empty()) {
			return -1;
		} // 스택이 비었다면 -1을 반환
		else {
			return topNode->data;
		} // topNode의 데이터를 반환
	}

	void push(int data) {
		node* newNode = new node;
		newNode->data = data; // 새로운 노드에 데이터를 삽입
		newNode->next = topNode; // 새로운 top이 newNode가 되므로 next는 기존의 topNode
		topNode = newNode; // newNode가 새로운 topNode가 된다
		listsize++; // 노드가 추가되었으니, listsize를 1 증가
	}

	void pop() {
		if (empty()) {
			return;
		} // 스택이 비어있는 경우 종료
		node* curNode = topNode; // 삭제될 노드의 메모리를 해제하기 위해 curNode 선언
		topNode = topNode->next; // topNode는 그 다음 노드가 된다
		delete curNode; // 기존 topNode의 메모리를 해제
		listsize--; // 노드가 삭제되었으니, listsize를 1 감소

	}
};