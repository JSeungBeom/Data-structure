#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class stack {
private:
	node* head; // stack에서 top의 위치와 데이터를 저장할 노드
	node* tail; 
	int listsize; // stack의 사이즈

public:
	stack() {
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
	} // 스택이 비었는지 판단

	int size() {
		return listsize;
	} // 스택의 크기를 리턴

	void push(int x) {
		node* newNode = new node;
		newNode->data = x;
		// stack의 top에 추가될 데이터
		if (empty()) {
			newNode->next = NULL;
			head = tail = newNode;
		} // stack이 비었다면, head와 tail 모두 newNode를 저장
		else {
			newNode->next = head;
			head = newNode;
		} // top(head)에 데이터를 삽입하므로, 새 노드의 다음 노드는 head가 되고, 새 노드는 head가 된다
		listsize++; 
		top();
	} // top에 데이터를 추가하는 함수

	void pop() {
		if (empty()) {
			cout << "Stack empty" << endl;
			return;
		} // 스택이 비었다면 pop을 진행할 수 없다
		else if (size() == 1) {
			cout << head->data << endl;
			head = tail = NULL;
		} // 스택의 사이즈가 1인 상태에서, 데이터를 삭제하면 스택이 비어있는 상태가 된다
		else {
			cout << head->data << endl;
			node* topNode = head;
			head = head->next;
			delete topNode;
		} // top(head)의 데이터를 삭제하므로, head는 그 다음 노드가 되고, head였던 노드는 메모리 해제
		listsize--;
	}

	void top() {
		cout << head->data << endl;
	} // top의 데이터를 출력하는 함수
};

int main() {
	int n;

	cin >> n;

	stack st;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "pop") {
			st.pop();
		}
		else if (s == "top") {
			st.top();
		}
		else if (s == "empty") {
			st.empty();
		}
		else if (s == "size") {
			st.size();
		}
		else
			break;
	}
}

/*
singlylinkedlist로 구현한 stack의 모든 기능은 head를 top으로 하였을 때,
O(1)의 시간 복잡도를 갖고, O(n)의 공간 복잡도를 가지므로, 효율적인 자료형이라고 할 수 있다.
*/
