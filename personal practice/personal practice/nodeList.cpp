#include <iostream>
#include <list>
using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};

class nodeList {
private:
	node* head;
	node* tail;
	int n;

public:
	nodeList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = NULL; // head와 tail이 서로를 가리키고 있는 형태
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	node* begin() {
		return head->next;
	}

	node* end() {
		return tail;
	}

	// pos의 앞에 data를 삽입
	void insert(node* pos, int data) {
		node* newNode = new node();
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos; // 매달린 상태
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
		if (empty()) {
			return;
		}
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
// O(n)의 공간복잡도, 각 연산은 O(1) time에 수행

int main() {

}