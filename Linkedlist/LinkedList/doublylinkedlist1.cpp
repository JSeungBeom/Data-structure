#include <iostream>

using namespace std;

struct node {
	int data; // 노드에 저장될 데이터
	node* next; // 다음 노드를 가리킬 포인터
	node* prev; // 이전 노드를 가리킬 포인터
};
class doublylinkedlist {
private:
	node* header; // 맨 앞의 노드를 가리킬 포인터
	node* trailer; // 맨 뒤 노드를 가리킬 포인터
	int listsize; // 리스트의 크기

public:
	doublylinkedlist() {
		header = NULL;
		trailer = NULL;
		listsize = 0;
	} // 멤버 변수 초기화

	void print() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = header;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	} // 리스트 출력 함수

	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // 배열이 비었는지 판단하는 함수

	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			newNode->prev = NULL;
			header = trailer = newNode;
		}
		else {
			trailer->next = newNode; // 기존 trailer의 next는 newNode가 되야한다
			newNode->prev = trailer;// newNode의 prev는 기존의 trailer이다
			trailer = newNode; // trailer가 newNode로 할당된다
		} // newNode를 tail 뒤에 추가
		listsize++;
		print();
	}

	void deletion(int idx) {
		if (idx < 0 || idx >= listsize || empty()) {
			cout << -1 << endl;
			return;
		} // 리스트의 크기보다 작거나, 크거나, 리스트가 비어있다면 -1 출력
		node* curNode = header;
		if (idx == 0) {
			if (listsize == 1) {
				cout << header->data << endl;
				header = trailer = NULL;
			} // 삭제했을때 리스트가 비게되므로, header와 trailer는 NULL이 된다
			else {
				cout << header->data << endl;
				header = header->next;
				header->prev = NULL;
			} // 0번째 노드를 삭제하므로, header는 그 다음 노드가 된다. header->prev는 NULL로 다시 초기화 해줘야한다
		}
		else{
			node* preNode = header;
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;

			}

			if (curNode == trailer) {
				cout << trailer->data << endl;
				trailer = trailer->prev;
				trailer->next = NULL;
				listsize--;
				return;
			} // curNode가 trailer라면 trailer는 curNode의 이전 노드가 되고, trailer의 다음 노드는 NULL로 초기화
			cout << curNode->data << endl;
			curNode->next->prev = preNode; // curNode의 다음 노드의 이전 노드는 preNode가 된다
			preNode->next = curNode->next; // preNode의 다음 노드는 curNode의 다음 노드가 된다
		}
		delete curNode;
		listsize--;
	} 

	void print_reverse() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = trailer;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode ->prev;
		}
		cout << endl;
	}// doublylinkedlist의 prev를 이용하여 반대로 출력하는 함수

	void max() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = header;
		int max = curNode->data;
		while (curNode != NULL) {
			if (max < curNode->data) {
				max = curNode->data;
			}
			curNode = curNode->next;
		}
		cout << max << endl;
	}
}; // 리스트 중 최댓값을 출력

int main() {
	int m;
	doublylinkedlist d;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int idx, data;
		if (s == "Print_reverse") {
			d.print_reverse();
		}
		else if (s == "Print") {
			d.print();
		}
		else if (s == "Append") {
			cin >> data;
			d.append(data);
		}
		else if (s == "Delete") {
			cin >> idx;
			d.deletion(idx);
		}
		else if (s == "Max") {
			d.max();
		}
		else
			break;
	}
}