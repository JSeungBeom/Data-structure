#include <iostream>

using namespace std;

struct node {
	node* next; // ����� ��ũ�� ������ ����
	int data; // ����� �����͸� ������ ����
};

class listQueue {
private:
	node* frontNode; // ��ũ�帮��Ʈ���� head�� ���� ����
	node* rearNode; // ��ũ�帮��Ʈ���� tail�� ���� ����
	int n; // ���� ť�� ������

public:
	listQueue() {
		frontNode = NULL; 
		rearNode = NULL;
		n = 0;
	} // ��� ���� �ʱ�ȭ

	int size() {
		return n;
	} // ť�� ������ ����

	bool empty() {
		return (n == 0);
	} // ť�� ������� �Ǵ�

	int front() {
		if (empty()) {
			return -1;
		} // ť�� ����ٸ� -1 ���� �� ����
		return frontNode->data; // ť�� front�� �ش��ϴ� ������ ����
	} // ť�� front ��ġ�� ������ ����

	void enqueue(int data) {
		node* newNode = new node; // ���ο� ��� ����
		newNode->data = data; // ���ο� ��忡 ������ ����
		newNode->next = NULL; // ���ο� ���� rearNode ������ ���Ե� ���̹Ƿ�, next�� NULL
		if (empty()) {
			frontNode = rearNode = newNode;
		} // ť�� ����ִٸ�, frontNode�� rearNode ��� newNode
		else {
			rearNode->next = newNode; // rearNode�� ���� ��尡 newNode�� �ȴ�
			rearNode = newNode;// rearNode�� newNode�� ����
		}
		n++; // ť ������ ����
	}

	void dequeue() {
		if (empty()) {
			return;
		} // ť�� ����ִٸ� ����
		
		if (size() == 1) {
			frontNode = rearNode = NULL;
		} // ť�� ����� 1�̶��, frontNode�� rearNode ��� NULL 
		else {
			node* curNode = frontNode; // ������ ��带 ����
			frontNode = frontNode->next; // frontNode�� �� ���� ��尡 �ȴ�
			delete curNode; // ������ ����� �޸𸮸� ����
		}
		n--;
	}
};

/*
	Queue�� stack(LIFO, Last-In First-Out)�� �޸�, FIFO(First-in First-Out) ������ �ڷᱸ���̴�.
	����, topNode�� �ʿ��� stack�� �޸�, �����Ͱ� �����Ǵ� frontNode�� ���ԵǴ� rearNode�� �ʿ��ϴ�.
	��ũ�� ����Ʈ�� �̿��� abstract data type (�߻� �ڷ���) Queue�� ���� �ÿ���,
	O(n) (n�� ����� ����)�� ���� ���⵵�� ������, ��� ����� O(1) (constant time)�ð��� ������ �ȴ�.
*/

int main() {
	listQueue q;

	q.enqueue(1); // 1
	q.enqueue(2); // 1 2
	q.enqueue(3); // 1 2 3
	cout << q.front() << " "; // ���� ť�� front�� 1
	q.dequeue(); // 2 3
	cout << q.front() << " "; // ���� ť�� front�� 2
}