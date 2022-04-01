#include <iostream>

using namespace std;

struct node {
	int data; // 데이터 필드
	node* prev; // 이전 노드를 가리키는 링크 필드
	node* next; // 다음 노드를 가리키는 링크 필드
};

class nodeList {
private:
	node* header; // 맨 앞의 노드
	node* trailer; // 맨 뒤의 노드
	int n; // list의 사이즈
public:
	// 생성자, 멤버 변수 초기화
	nodeList() {
		header = new node();
		trailer = new node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL; // header와 trailer가 서로를 가리키는 형태
		n = 0;
	};

	// list가 비었는지 판단하는 함수
	bool empty() {
		return (n == 0);
	};

	// list의 크기를 리턴
	int size() {
		return n;
	}

	// list의 header의 next 주소를 반환
	node* begin() {
		return header->next;
	}

	// list의 trailer의 주소 반환
	node* end() {
		return trailer;
	}

	// pos가 가리킼는 노드 앞쪽에 data를 삽입하는 함수
	void insert(node* pos, int data) {
		node* newNode = new node; // 새로운 노드
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos;
		// newNode가 기존 리스트에 매달린 형태
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertFront(int data) {
		insert(begin(), data);
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	void erase(node* pos) {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		n--;
	}

	void eraseFront() {
		erase(begin());
	}

	void eraseBack() {
		erase(end()->prev);
	}
};

/* doubly linked list를 이용한 list의 구현에서는, O(n)의 space - complexity를 가지며,
	모든 기능들이 O(1) time-complexity를 갖는다.
*/
