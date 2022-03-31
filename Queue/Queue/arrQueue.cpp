#include <iostream>

using namespace std;

class arrayQueue {
private:
	int* arr; // 큐의 원소를 저장할 배열
	int capacity; // 큐의 최대 크기
	int frontidx; // 큐의 front 위치를 저장하는 변수
	int rearidx; // 큐의 rear - 1의 위치를 저장하는 변수
	int n; // 현재 큐의 크기

public:
	arrayQueue(int capacity) {
		this->capacity = capacity;
		frontidx = 0;
		rearidx = 0;
		arr = new int[capacity];
		n = 0;
	} // 멤버 변수 초기화

	int size() {
		return n;
	} // 큐의 현재 크기를 리턴하는 함수

	bool empty() {
		return (n == 0);
	} // 큐가 비어있는지 확인하는 함수

	int front() {
		if (empty()) {
			return -1;
		} // 큐가 비어있을 경우, -1 리턴
		return arr[frontidx];
	} // 큐의 front에 저장된 원소를 리턴

	void enqueue(int data) {
		if (size() == capacity) {
			return;
		} // 큐가 가득 찬 경우, 종료
		arr[rearidx] = data; // 큐의 rear + 1의 위치에 데이터 삽입
		rearidx = (rearidx + 1) % capacity; // rearidx가 큐의 최대 크기를 넘어서면, 다시 0부터 삽입
		n++; // 큐의 사이즈 증가
	}

	void dequeue() {
		if (empty()) {
			return;
		} // 큐가 비어있을 경우, 종료
		frontidx = (frontidx + 1) % capacity; // frontidx가 큐의 최대 크기를 넘어서면, 다시 0부터 삭제
		n--;
	}
};
/*
	Queue는 stack(LIFO, Last-In First-Out)과 달리, FIFO(First-in First-Out) 형태의 자료구조이다.
	따라서, topIndex만 필요한 stack과 달리, 데이터가 삭제되는 frontindex와 삽입되는 rearindex가 필요하다.
	배열을 이용하여 abstract data type(추상 자료형) queue를 구현 할때에는 환형 배열로 구현하여,
	배열의 공간을 효과적으로 활용할 수 있다. 환형 배열은 
	만약 인덱스가 배열의 최대 크기를 넘어서는 경우, 다시 0부터 삽입하는 형태이다.
	배열을 이용한 queue의 구현은 O(N) (N은 배열의 최대 크기)의 공간 복잡도를 가지고,
	모든 기능은 O(1) (constant time)의 시간에 동작한다. 
*/

int main() {
	arrayQueue q(10);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << q.front() << " ";
	// 큐의 frontidx에는 1이 저장
	q.dequeue(); // 큐의 front 데이터 1 삭제
	cout << q.front() << " ";
	// 큐의 frontidx에는 2가 저장

}