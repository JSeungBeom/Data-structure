#include <iostream>

using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;

public:
	// 생성자
	nodeList() {
		header = new node;
		trailer = new node;
		header->data = 0;
		trailer->data = 0;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	node* begin() {
		return header->next;
	}

	node* end() {
		return trailer;
	}

	// 링크드 리스트의 trailer 앞에 데이터 삽입
	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = trailer;
		newNode->prev = trailer->prev;
		trailer->prev->next = newNode;
		trailer->prev = newNode;
		n++;
	}

	// 인접한 노드들끼리의 최대값과 최솟값의 차를 구하는 함수
	void max_minus_min() {
		node* curNode = begin();
		while (curNode != end()) {
			int max = curNode->data;
			int min = curNode->data;
			if (curNode->prev->data > max && curNode->prev != header) {
				max = curNode->prev->data;
			}
			if (curNode->next->data > max && curNode->next != trailer) {
				max = curNode->next->data;
			}

			if (curNode->prev != header && curNode->prev->data < min) {
				min = curNode->prev->data;
			}
			if (curNode->next != trailer && curNode->next->data < min) {
				min = curNode->next->data;
			}
			cout << max - min << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int size;
		cin >> size;
		nodeList list;
		for (int j = 0; j < size; j++) {
			int data;
			cin >> data;
			list.append(data);
		}
		list.max_minus_min();
	}
}