#include <iostream>

using namespace std;

struct node {
	node* next; // 노드의 링크를 저장할 변수
	int data; // 노드의 데이터를 저장할 변수
};

class listQueue {
private:
	node* frontNode; // 링크드리스트에서 head와 같은 역할
	node* rearNode; // 링크드리스트에서 tail과 같은 역할
	int n; // 현재 큐의 사이즈

public:
	listQueue() {
		frontNode = NULL; 
		rearNode = NULL;
		n = 0;
	} // 멤버 변수 초기화

	int size() {
		return n;
	} // 큐의 사이즈 리턴

	bool empty() {
		return (n == 0);
	} // 큐가 비었는지 판단

	int front() {
		if (empty()) {
			return -1;
		} // 큐가 비었다면 -1 리턴 후 종료
		return frontNode->data; // 큐의 front에 해당하는 데이터 리턴
	} // 큐의 front 위치에 데이터 리턴

	void enqueue(int data) {
		node* newNode = new node; // 새로운 노드 생성
		newNode->data = data; // 새로운 노드에 데이터 삽입
		newNode->next = NULL; // 새로운 노드는 rearNode 다음에 삽입될 것이므로, next는 NULL
		if (empty()) {
			frontNode = rearNode = newNode;
		} // 큐가 비어있다면, frontNode와 rearNode 모두 newNode
		else {
			rearNode->next = newNode; // rearNode의 다음 노드가 newNode가 된다
			rearNode = newNode;// rearNode는 newNode로 갱신
		}
		n++; // 큐 사이즈 증가
	}

	void dequeue() {
		if (empty()) {
			return;
		} // 큐가 비어있다면 종료
		
		if (size() == 1) {
			frontNode = rearNode = NULL;
		} // 큐의 사이즈가 1이라면, frontNode와 rearNode 모두 NULL 
		else {
			node* curNode = frontNode; // 삭제할 노드를 저장
			frontNode = frontNode->next; // frontNode는 그 다음 노드가 된다
			delete curNode; // 삭제된 노드의 메모리를 해제
		}
		n--;
	}
};

/*
	Queue는 stack(LIFO, Last-In First-Out)과 달리, FIFO(First-in First-Out) 형태의 자료구조이다.
	따라서, topNode만 필요한 stack과 달리, 데이터가 삭제되는 frontNode와 삽입되는 rearNode가 필요하다.
	링크드 리스트를 이용한 abstract data type (추상 자료형) Queue를 구현 시에는,
	O(n) (n은 요소의 개수)의 공간 복잡도를 가지고, 모든 기능은 O(1) (constant time)시간에 수행이 된다.
*/

int main() {
	listQueue q;

	q.enqueue(1); // 1
	q.enqueue(2); // 1 2
	q.enqueue(3); // 1 2 3
	cout << q.front() << " "; // 현재 큐의 front는 1
	q.dequeue(); // 2 3
	cout << q.front() << " "; // 현재 큐의 front는 2
}