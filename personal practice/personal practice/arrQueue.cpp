#include <iostream>

using namespace std;

class arrQueue {
private:
	int* arr;
	int capacity; // 배열의 최대 크기
	int frontidx; // 큐의 front 위치의 인덱스
	int rearidx; // 큐의 rear + 1 위치의 인덱스
	int n; // 큐의 크기

public:
	arrQueue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = n = 0; // 초기에 frontidx, rearidx 모두 0으로 초기화
	}

	// 큐의 사이즈 리턴
	int size() {
		return n;
	}

	// 큐가 비었는지 판단
	bool empty() {
		return (n == 0);
	}

	// 큐의 rear에서 데이터 삽입
	void enqueue(int data) {
		if (n == capacity) {
			return;
		}
		arr[rearidx] = data; // rear + 1 위치의 rearidx에 data 삽입
		rearidx = (rearidx + 1) % capacity; // rearidx를 1 증가, 배열의 크기를 넘어서면 다시 0부터 삽입
		n++; // 큐 사이즈 증가
	}

	// 큐의 front에서 데이터 삭제
	void dequeue() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity; // frontidx를 1 증가, 배열의 크기를 넘어서면 다시 0부터 삭제
		n--; // 큐의 사이즈 감소
	}

	// 큐의 front에 data 리턴
	int front() {
		if (empty()) {
			return -1;
		}
		return arr[frontidx];
	}
};

int main() {
	arrQueue aq(10);
	aq.enqueue(3);
	aq.enqueue(4);
	aq.enqueue(5);
	cout << aq.front() << endl;
	aq.dequeue();
	cout << aq.front() << endl;
}