#include <iostream>

using namespace std;

struct node {
	node* next;
	int data;
};

class stack {
private:
	node* topNode; // 링크드리스트에서 head와 비슷한 역할
	int listsize; // 스택의 사이즈

public:
	stack() {
		topNode = NULL;
		listsize = 0;
	} // 생성자로 멤버 변수 초기화

	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // 스택이 비었으면 true, 아니라면 false 반환

	int size() {
		return listsize;
	} // 스택의 사이즈 반환

	void push(int data) {
		node* newNode = new node; // 삽입할 노드
		newNode->data = data; // 삽입할 노드에 데이터 삽입
		newNode->next = topNode; // topNode 앞에 삽입하므로 next는 topNode
		topNode = newNode; // 새로운 topNode가 된다
		listsize++; // 스택 사이즈 1 증가
	} // 스택의 topNode 앞에 노드 삽입

	void pop() {
		if (empty()) {
			return;
		} // 비어있다면 종료
		node* curNode = topNode;
		topNode = topNode->next;
		delete curNode;
		listsize--;
	} // 현재 topNode를 그 다음 노드로 바꾸고, 기존 topNode를 삭제

	int top() {
		if (empty()) {
			return -1;
		}
		return topNode->data;
	} // 비어있다면 종료하고, 아니라면 탑노드의 데이터를 반환

	
};