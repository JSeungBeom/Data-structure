#include <iostream>

using namespace std;

class Queue {
private:
	int* arr; 
	int capacity;
	int frontidx;
	int rearidx;
	int n;
	int point; // �� �÷��̾��� ���� ����

public:
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = n = point = 0;
	} // ������

	int size() {
		return n;
	} // ť�� ũ�� ����

	bool empty() {
		return (n == 0);
	} // ť�� ������� �Ǵ�

	int front() {
		if (empty()) {
			return -1;
		}
		return arr[frontidx];
	} // ť�� front ������ ����

	void enqueue(int data) {
		if (size() == capacity) {
			return;
		}
		arr[rearidx] = data;
		rearidx = (rearidx + 1) % capacity;
		n++;
	} // ť�� rearidx�� ������ ����

	void dequeue() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity;
		n--;
	} // ť�� frontidx�� ������ ����

	void add_point() {
		point++;
	} // ���� ����

	int get_point() {
		return point;
	} // ���� ����

	void add_front(int dif) {
		arr[frontidx] += dif;
	} // �� ����� ���� ī���� ü���� ü���� ���� ��ŭ ����

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
		} // n���� x�� ť p1�� ����
		for (int j = 0; j < n; j++) {
			int y;
			cin >> y;
			p2.enqueue(y);
		} // n���� y�� ť p2�� ����
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