#include <iostream>

using namespace std;

class Queue {
private:
	int* arr; 
	int capacity;
	int frontidx;
	int rearidx;
	int n;
	int point; // 각 플레이어의 점수 저장

public:
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = n = point = 0;
	} // 생성자

	int size() {
		return n;
	} // 큐의 크기 리턴

	bool empty() {
		return (n == 0);
	} // 큐가 비었는지 판단

	int front() {
		if (empty()) {
			return -1;
		}
		return arr[frontidx];
	} // 큐의 front 데이터 리턴

	void enqueue(int data) {
		if (size() == capacity) {
			return;
		}
		arr[rearidx] = data;
		rearidx = (rearidx + 1) % capacity;
		n++;
	} // 큐의 rearidx에 데이터 삽입

	void dequeue() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity;
		n--;
	} // 큐의 frontidx에 데이터 삭제

	void add_point() {
		point++;
	} // 승점 증가

	int get_point() {
		return point;
	} // 승점 리턴

	void add_front(int dif) {
		arr[frontidx] += dif;
	} // 진 사람의 다음 카드의 체력을 체력의 차이 만큼 증가

};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		Queue p1(n);
		Queue p2(n);
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			p1.enqueue(x);
		} // n개의 x를 큐 p1에 삽입
		for (int j = 0; j < n; j++) {
			int y;
			cin >> y;
			p2.enqueue(y);
		} // n개의 y를 큐 p2에 삽입
		for (int j = 1; j <= n; j++) {
			cout << "Round" << j << " ";
			int dif = abs(p1.front() - p2.front());
			if (p1.front() > p2.front()) {
				cout << "P1 " << dif << endl;
				p1.add_point();
				p1.dequeue();
				p2.dequeue();
				p2.add_front(dif);
			}
			else {
				if (p1.front() == p2.front()) {
					cout << "Draw" << endl;
					p1.dequeue();
					p2.dequeue();
				}
				else {
					cout << "P2 " << dif << endl;
					p2.add_point();
					p1.dequeue();
					p2.dequeue();
					p1.add_front(dif);
				}
			}
		}
		if (p1.get_point() > p2.get_point()) {
			cout << "Winner P1" << endl;
		}
		else {
			if (p1.get_point() == p2.get_point())
				cout << "Draw" << endl;
			else
				cout << "Winner P2" << endl;
		}
	}
}