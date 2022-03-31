#include <iostream>

using namespace std;

class Queue {
private:
	int* arr; // 큐 배열
	int capacity; // 큐의 최대 크기
	int frontidx; // 데이터의 삭제를 할 frontidx
	int rearidx; // 데이터의 삽입을 할 rearidx
	int n; // 큐의 현재 크기

public:
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = 0;
		n = 0;
	} // 생성자

	int size() {
		return n;
	} // 큐의 크기 리턴

	bool empty() {
		return (n == 0);
	} // 큐가 비었는지 판단

	void front() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << arr[frontidx] << endl;
	} // 큐의 frontidx 데이터 출력

	void rear() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		if (rearidx == 0) {
			cout << arr[capacity - 1] << endl;
		}
		else
		cout << arr[rearidx - 1] << endl;
	} // 큐의 rearidx - 1 데이터 출력

	void enqueue(int value) {
		if (size() == capacity) {
			cout << "Full" << endl;
			return;
		}
		arr[rearidx] = value;
		rearidx = (rearidx + 1) % capacity;
		n++;
	} // 큐의 rearidx에 데이터 삽입

	void dequeue() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		front();
		frontidx = (frontidx + 1) % capacity;
		n--;
	} // 큐의 frontidx 데이터 삭제
};

int main() {
	int n, t;
	cin >> n >> t;

	Queue q(n);

	for (int i = 0; i < t; i++){
		string s;
		cin >> s;
		if (s == "isEmpty") {
			if (q.empty()) {
				cout << "True" << endl;
			}
			else
				cout << "False" << endl;
		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
		else if (s == "enqueue") {
			int value;
			cin >> value;
			q.enqueue(value);
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
	}
}