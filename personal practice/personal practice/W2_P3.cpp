#include <iostream>

using namespace std;

// 노드 구조체
struct node {
	int data; // 데이터 필드
	node* next; // 링크 필드
};

class singlyLinkedList {
private:
	node* head; // 리스트의 맨 앞 노드
	node* tail; // 리스트의 맨 뒷 노드
	int n; // 리스트의 크기

public:
	// 생성자
	singlyLinkedList() {
		head = tail = NULL;
		n = 0;
	}

	// 리스트의 크기 리턴
	int size() {
		return n;
	}
	
	// 리스트가 비었는지 판단
	bool empty() {
		return (n == 0);
	}

	// 리스트의 tail 뒤에 노드 삽입
	void append(int data) {
		node* newNode = new node; // 새로운 노드 할당
		newNode->data = data; // 데이터 삽입
		newNode->next = NULL; // tail에 삽입하니, next는 NULL
		// 빈 리스트에 삽입할 때
		if (empty()) {
			head = tail = newNode; 
		}
		else {
			tail->next = newNode; // tail의 next는 newNode
			tail = newNode; // tail이 newNode로 업데이트
		}
		n++; // 리스트 사이즈 증가
		print();
	}

	// 리스트에 노드 삽입
	void insertion(int idx, int data) {
		// exception handling
		if (idx < 0 || idx > n) {
			cout << "Index Error" << endl;
			return;
		}
		// idx가 리스트의 크기와 같을 때, append함수와 같다
		else if (idx == n) {
			append(data);
		}
		// idx 가 0일 때, head 앞에 삽입
		else if (idx == 0) {
			node* newNode = new node;
			newNode->data = data;
			newNode->next = head; // newNode의 next는 head
			head = newNode; // newNode가 새로운 head
			n++;
			print();
		}
		else {
			node* newNode = new node;
			newNode->data = data;
			node* curNode = head;
			for (int i = 1; i < idx; i++) {
				curNode = curNode->next;
			}
			newNode->next = curNode->next;
			curNode->next = newNode;
			n++;
			print();
		}
	}

	// 리스트에서 노드 삭제
	void deletion(int idx) {
		if (idx < 0 || idx >= n || empty()) {
			cout << -1 << endl;
			return;
		}
		node* curNode = head;
		if (idx == 0) {
			if (n == 1) {
				cout << curNode->data << endl;
				head = tail = NULL;
			}
			else {
				cout << curNode->data << endl;
				head = head->next;
			}
		}
		else {
			node* preNode = head;
			// 링크드리스트에서 인덱싱은 최악의 경우(tail에서의 삭제) O(n) 시간이 걸린다.
			for (int i = 0; i < idx; i++) {
				preNode = curNode;
				curNode = curNode->next;
			}
			cout << curNode->data << endl;
			preNode->next = curNode->next;
			if (curNode == tail) {
				tail = preNode;
			}
		}
		n--;
	}

	void print() {
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		node* curNode = head;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}

	void sum() {
		if (empty()) {
			cout << 0 << endl;
			return;
		}
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
	cin >> m;
	singlyLinkedList li;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int idx, data;
		if (s == "Print") {
			li.print();
		}
		else if (s == "Append") {
			cin >> data;
			li.append(data);
		}
		else if (s == "Delete") {
			cin >> idx;
			li.deletion(idx);
		}
		else if (s == "Insert") {
			cin >> idx>> data;
			li.insertion(idx,data);
		}
		else if (s == "Sum") {
			li.sum();
		}
	}
}

/*
	LinkedList : Concrete data structure consisting of a sequence of nodes
	Each node stores element, link to the next node
	head에서의 삽입: O(1) time newNode->next = head; head = newNode;
	head에서의 삭제: O(1) time head = head->next;
	tail에서의 삽입: O(1) time tail->next = newNode; tail = newNode;
	tail에서의 삭제: O(n) time tail 이전 노드를 찾기 위해, indexing이 필요(not efficient)
	공간 복잡도 : O(n)
*/