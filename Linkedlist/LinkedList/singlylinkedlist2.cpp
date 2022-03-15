#include <iostream>

using namespace std;

struct node {
	int data; // 실질적인 data를 저장할 변수
	node* next; // 다음 node를 가리킬 변수
};

class singlylinkedlist {
private:
	node* head; // 리스트의 처음을 가리킬 변수
	node* tail; // 리스트의 마지막을 가리킬 변수
	int listsize; // 리스트의 크기

public:
	singlylinkedlist() {
		head = NULL;
		tail = NULL;
		listsize = 0;
	}
	bool empty() {
		if (listsize == 0) {
			return true;
		}
		else
			return false;
	} // 리스트가 비었다면 true 아니라면 false를 반환

	void append(int x) {
		node* newNode = new node;
		newNode->data = x;
		newNode->next = NULL;
		if (empty()) {
			head = tail = newNode;
		} // 리스트가 비었다면, head와 tail 모두 newNode를 가리키가 된다
		else {
			tail->next = newNode;
			tail = newNode;
		} // 비어있지 않다면, tail의 뒤에 newNode를 삽입하므로 tail의 next는 newNode가 되고, 새로운 tail은 newNode가 된다
		listsize++; // node를 추가하였으므로, listsize를 증가시킨다
		print(); // 삽입이 끝났으므로, 리스트를 출력
	}

	void print() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* curNode = head; // head부터 차례대로 데이터를 출력
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		} // curNode가 NULL이 될 때까지, 데이터를 출력하고 다음 node로 진행
		cout << endl;
	} // 리스트 출력

	void deletion(int idx) {
		if (idx < 0 || idx >= listsize || empty()) {
			cout << -1 << endl;
			return;
		} // 인덱스가 0보다 작거나, listsize 이상이거나, 리스트가 비어있다면 -1을 출력하고 return
		node* curNode = head;
		if (idx == 0) {
			if (listsize == 1) {
				cout << head->data << endl;
				head = tail = NULL;
			} // 첫번째의 데이터를 삭제하면 listsize가 0이 되는 경우이므로, head와 tail이 NULL이 된다
			else {
				cout << head->data << endl;
				head = head->next;
			} // 첫번째의 데이터를 삭제하면, head는 head의 next가 된다
		}
		else {
			node* preNode = head; // curNode의 이전 node를 저장할 포인터 변수
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			} // idx - 1까지 반복하며, 최종적으로 preNode는 curNode의 이전 노드가 되고, 삭제하고자 하는 index는 curNode가 된다
			cout << curNode->data << endl;
			preNode->next = curNode->next; // preNode의 next는 curNode가 삭제되고, curNode의 next를 가리킨다
			if (curNode == tail) {
				tail = preNode;
			} // 삭제한 node가 tail이었다면, preNode가 tail이 되야한다
		}
		delete curNode;
		listsize--;
	}

	void insertion(int idx, int data) {
		if (idx < 0 || idx > listsize) {
			cout << "Index Error" << endl;
			return;
		} // 삽입하고자 하는 위치가, 리스트를 벗어난 범위일 경우 index error 출력
		else if (listsize == idx) {
			append(data);
		} // 리스트사이즈와 인덱스가 같다면, tail 뒤에 데이터를 삽입하는 append() 함수를 실행시키는 것과 동일하다
		else {
			if (idx == 0) {
				node* newNode = new node; // 새로 삽입하는 노드
				newNode->data = data; // 노드의 데이터
				newNode->next = head; // 노드의 next는 head
				head = newNode; // head를 newNode로 갱신
				listsize++;
				print();
			} // 삽입하고자 하는 index가 0이라면, 새로 삽입하는 node의 next는 head가 되고, head는 node로 갱신
			else {
				node* newNode = new node;
				node* curNode = head;
				newNode->data = data;
				for (int i = 1; i < idx; i++) {
					curNode = curNode->next;
				} // 삽입하고자 하는 위치를 찾기 위해서 index위치의 노드를 탐색
				newNode->next = curNode->next; // newNode의 next는 curNode의 next를 가리킨다
				curNode->next = newNode; // curNode의 next는 newNode가 된다
				listsize++;
				print();
			}
		}

	}
	
	void sum() {
		if (empty()) {
			cout << 0 << endl;
			return;
		} // 비어있다면 0 출력하고 리턴
		int sum = 0;
		node* curNode = head;
		while (curNode != NULL) {
			sum += curNode->data;
			curNode = curNode->next;
		}
		cout << sum << endl;
	}
};


int main() {
	int m;

	singlylinkedlist li;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int data, index;
		if (s == "Append") {
			cin >> data;
			li.append(data);
		}
		else if (s == "Delete") {
			cin >> index;
			li.deletion(index);
		}
		else if (s == "Print") {
			li.print();
		}
		else if (s == "Insert") {
			cin >> index >> data;
			li.insertion(index, data);
		}
		else if (s == "Sum") {
			li.sum();
		}
		else
			break;
	}

}