#include <iostream>

using namespace std;

struct node {
	node* next;
	int data;
};

class stack {
private:
	node* topNode; // ��ũ�帮��Ʈ���� head�� ����� ����
	int listsize; // ������ ������

public:
	stack() {
		topNode = NULL;
		listsize = 0;
	} // �����ڷ� ��� ���� �ʱ�ȭ

	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // ������ ������� true, �ƴ϶�� false ��ȯ

	int size() {
		return listsize;
	} // ������ ������ ��ȯ

	void push(int data) {
		node* newNode = new node; // ������ ���
		newNode->data = data; // ������ ��忡 ������ ����
		newNode->next = topNode; // topNode �տ� �����ϹǷ� next�� topNode
		topNode = newNode; // ���ο� topNode�� �ȴ�
		listsize++; // ���� ������ 1 ����
	} // ������ topNode �տ� ��� ����

	void pop() {
		if (empty()) {
			return;
		} // ����ִٸ� ����
		node* curNode = topNode;
		topNode = topNode->next;
		delete curNode;
		listsize--;
	} // ���� topNode�� �� ���� ���� �ٲٰ�, ���� topNode�� ����

	int top() {
		if (empty()) {
			return -1;
		}
		return topNode->data;
	} // ����ִٸ� �����ϰ�, �ƴ϶�� ž����� �����͸� ��ȯ

	
};