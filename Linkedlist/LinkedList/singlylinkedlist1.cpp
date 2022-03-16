#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
}; // data와 다음 node의 주소를 저장할 node

class linkedlist {
private:
	node* head; // 노드의 맨 처음 주소
	node* tail; // 노드의 맨 마지막 주소
	int listsize; // 노드의 사이즈

public:
	linkedlist() {
		head = NULL;
		tail = NULL;
		listsize = 0;
	} // 멤버 변수 초기화

	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // listsize가 0이라면(링크드리스트가 비어있다면) true를 반환

	void append(int data) {
		node* newNode = new node; // 추가할 노드
		newNode->data = data; // 추가할 노드에 데이터 삽입
		newNode->next = NULL; // 추가할 노드는 tail에 추가되므로, next는 NULL
		if (empty()) {
			head = tail = newNode;
		} // 리스트가 비어있다면, head와 tail은 모두 newNode이다
		else {
			tail->next = newNode;
			tail = newNode;
		} // tail에 추가하는 함수이므로, tail의 next는 newNode가 되고, tail은 newNode가 된다
		listsize++; // listsize를 증가시킨다
		print();
	}
	void insertion(int idx, int data) {
		if (idx < 0 || idx > listsize) {
			cout << "Index Error" << endl;
			return;
		} // 인덱스가 0보다 작거나, listsize보다 클 경우, 추가할 수 없다
		else if (idx == listsize) {
			append(data);
		} // idx가 listsize와 동일할때는, tail에 데이터를 추가하는 것과 동일하다
		else if (idx == 0) {
			node* newNode = new node;
			newNode->data = data;
			newNode->next = head;
			head = newNode;
			listsize++;
			print();
		} // 인덱스가 0일때는, head에 추가하므로 head가 newNode가 된다
		else {
			node* newNode = new node;
			newNode->data = data;
			node* curNode = head; // 삽입할 위치를 찾을 node
			for (int i = 1; i < idx; i++) {
				curNode = curNode->next;
			} // 삽입할 위치까지 curNode를 이동한다
			newNode->next = curNode->next; // 새로운 노드의 next는 현재 노드였던 curNode의 next
			curNode->next = newNode; // 현재 노드인 curNode의 next는 newNode
			listsize++; // listsize 증가
			print();
		}
	}

	void deletion(int idx) {
		if (idx < 0 || idx >= listsize || empty()) {
			cout << -1 << endl;
			return;
		} // 인덱스가 0보다 작거나, listsize 이상이거나, 리스트가 비어있다면 노드를 삭제할 수 없다

		node* curNode = head; // 현재 노드의 위치를 계산
		if (idx == 0) {
			if (listsize == 1) {
				cout << head->data << endl;
				head = tail = NULL;
			} // 리스트사이즈가 1일 때, index 0을 삭제하면 배열은 비어있게 된다
			else {
				cout << head->data << endl;
				head = head->next;
			} // index 0을 삭제하면 head는 head의 next가 되고, head는 삭제 된다
		}
		else {
			node* preNode = head; // 현재 노드의 이전 노드를 계산
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			} // 계산
			cout << curNode->data << endl;
			preNode->next = curNode->next; // curNode를 삭제하므로, preNode의 next는 curNode의 next가 된다
			if (curNode == tail) {
				tail = preNode;
			} // curNode가 tail이었다면, preNode가 tail이 된다
		}
		delete curNode; // curNode의 메모리를 해제
		listsize--; // listsize 감소
	}
	void print() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		else {
			node* curNode = head;
			while (curNode != NULL) {
				cout << curNode->data << " ";
				curNode = curNode->next;
			} // curNode가 NULL이 될 때까지, curNode의 data를 출력
			cout << endl;
		}
	}

	void min() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		else {
			node* curNode = head;
			int min = head->data;
			while (curNode != NULL) {
				if (min > curNode->data) {
					min = curNode->data;
				}
				curNode = curNode->next;
			} // min을 head의 data로 두고, 리스트의 data들을 검사하면서 min보다 작으면 이를 min에 대입
			cout << min << endl;
		}
	}
};

int main() {
	int m;
	linkedlist li;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string s;
		int idx, data;
		cin >> s;

		if (s == "Append") {
			cin >> data;
			li.append(data);
		}
		else if (s == "Print") {
			li.print();
		}
		else if (s == "Delete") {
			cin >> idx;
			li.deletion(idx);
		}
		else if (s == "Insert") {
			cin >> idx >> data;
			li.insertion(idx, data);
		}
		else if (s == "Min") {
			li.min();
		}
		else
			break;
	}
}