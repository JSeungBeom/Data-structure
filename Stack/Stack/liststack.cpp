#include <iostream>

using namespace std;

struct node {
	int data; // ������ �ʵ�
	node* next; // ��ũ �ʵ�
};

class listStack {
private:
	node* topNode; // linkedlist�� head ����
	int listsize; // ������ ũ�⸦ ����

public:
	listStack() {
		topNode = NULL;
		listsize = 0;
	} // ��� ���� �ʱ�ȭ

	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // ������ ����ִ��� �Ǵ�

	int size() {
		return listsize;
	} // ������ ũ�⸦ ��ȯ

	int top() {
		if (empty()) {
			return -1;
		} // ������ ����ٸ� -1�� ��ȯ
		else {
			return topNode->data;
		} // topNode�� �����͸� ��ȯ
	}

	void push(int data) {
		node* newNode = new node;
		newNode->data = data; // ���ο� ��忡 �����͸� ����
		newNode->next = topNode; // ���ο� top�� newNode�� �ǹǷ� next�� ������ topNode
		topNode = newNode; // newNode�� ���ο� topNode�� �ȴ�
		listsize++; // ��尡 �߰��Ǿ�����, listsize�� 1 ����
	}

	void pop() {
		if (empty()) {
			return;
		} // ������ ����ִ� ��� ����
		node* curNode = topNode; // ������ ����� �޸𸮸� �����ϱ� ���� curNode ����
		topNode = topNode->next; // topNode�� �� ���� ��尡 �ȴ�
		delete curNode; // ���� topNode�� �޸𸮸� ����
		listsize--; // ��尡 �����Ǿ�����, listsize�� 1 ����

	}
};