#include <iostream>

using namespace std;

class Queue {
private:
	int* arr; // ť �迭
	int capacity; // ť�� �ִ� ũ��
	int frontidx; // �������� ������ �� frontidx
	int rearidx; // �������� ������ �� rearidx
	int n; // ť�� ���� ũ��

public:
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = 0;
		n = 0;
	} // ������

	int size() {
		return n;
	} // ť�� ũ�� ����

	bool empty() {
		return (n == 0);
	} // ť�� ������� �Ǵ�

	void front() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << arr[frontidx] << endl;
	} // ť�� frontidx ������ ���

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
	} // ť�� rearidx - 1 ������ ���

	void enqueue(int value) {
		if (size() == capacity) {
			cout << "Full" << endl;
			return;
		}
		arr[rearidx] = value;
		rearidx = (rearidx + 1) % capacity;
		n++;
	} // ť�� rearidx�� ������ ����

	void dequeue() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		front();
		frontidx = (frontidx + 1) % capacity;
		n--;
	} // ť�� frontidx ������ ����
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